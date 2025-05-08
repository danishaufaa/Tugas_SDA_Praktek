#include <stdio.h>
#include <stdlib.h>
#include "nbtrees.h"
#include <stdbool.h>

/* Fungsi pembantu untuk menginisialisasi node */
void initNode(nbtree *node, infotype info, address fs, address nb, address pr) {
    node->info = info;
    node->ps_fs = fs;
    node->ps_nb = nb;
    node->ps_pr = pr;
}

/* Membuat Pohon Non Biner dengan Jml node dalam urutan Level Order */
void Create_tree(Isi_Tree X, int Jml) {
    if (Jml < 1 || Jml > jml_maks) return;

    // Inisialisasi semua node sebagai kosong
    for (int i = 0; i <= jml_maks; i++) {
        initNode(&X[i], '\0', nil, nil, nil);
    }

    // Menetapkan node sesuai struktur pada Gambar 18 hingga level 2 (A hingga H)
    int i = 1;
    if (i <= Jml) { // Indeks 1: A
        initNode(&X[i], 'A', 2, nil, nil); // fs=B, nb=0, pr=0
        i++;
    }
    if (i <= Jml) { // Indeks 2: B
        initNode(&X[i], 'B', 5, 3, 1); // fs=E, nb=C, pr=A
        i++;
    }
    if (i <= Jml) { // Indeks 3: C
        initNode(&X[i], 'C', nil, 4, 1); // fs=0, nb=D, pr=A
        i++;
    }
    if (i <= Jml) { // Indeks 4: D
        initNode(&X[i], 'D', 7, nil, 1); // fs=G, nb=0, pr=A
        i++;
    }
    if (i <= Jml) { // Indeks 5: E
        initNode(&X[i], 'E', nil, 6, 2); // fs=0 (belum I), nb=F, pr=B
        i++;
    }
    if (i <= Jml) { // Indeks 6: F
        initNode(&X[i], 'F', nil, nil, 2); // fs=0, nb=0, pr=B
        i++;
    }
    if (i <= Jml) { // Indeks 7: G
        initNode(&X[i], 'G', nil, 8, 4); // fs=0, nb=H, pr=D
        i++;
    }
    if (i <= Jml) { // Indeks 8: H
        initNode(&X[i], 'H', nil, nil, 4); // fs=0, nb=0, pr=D
        i++;
    }
}

/* Memeriksa apakah pohon kosong */
bool IsEmpty(Isi_Tree P) {
    return P[1].info == '\0';
}

/* Penelusuran Preorder: Orang tua, Anak pertama, Saudara berikutnya */
void Preorder_recursive(Isi_Tree P, address idx) {
    if (idx == nil || P[idx].info == '\0') return;
    printf("%c ", P[idx].info); // Mengunjungi orang tua
    Preorder_recursive(P, P[idx].ps_fs); // Mengunjungi anak pertama
    Preorder_recursive(P, P[idx].ps_nb); // Mengunjungi saudara berikutnya
}

void Preorder(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Pohon kosong\n");
        return;
    }
    Preorder_recursive(P, 1);
    printf("\n");
}

/* Penelusuran Inorder: Anak pertama, Orang tua, Anak lainnya */
void Inorder_recursive(Isi_Tree P, address idx) {
    if (idx == nil || P[idx].info == '\0') return;
    Inorder_recursive(P, P[idx].ps_fs); // Mengunjungi anak pertama
    printf("%c ", P[idx].info); // Mengunjungi orang tua
    address sibling = P[idx].ps_fs;
    while (sibling != nil) {
        Inorder_recursive(P, P[sibling].ps_nb); // Mengunjungi anak lainnya
        sibling = P[sibling].ps_nb;
    }
}

void Inorder(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Pohon kosong\n");
        return;
    }
    Inorder_recursive(P, 1);
    printf("\n");
}

/* Penelusuran Postorder: Anak pertama, Saudara berikutnya, Orang tua */
void Postorder_recursive(Isi_Tree P, address idx) {
    if (idx == nil || P[idx].info == '\0') return;
    Postorder_recursive(P, P[idx].ps_fs); // Mengunjungi anak pertama
    Postorder_recursive(P, P[idx].ps_nb); // Mengunjungi saudara berikutnya
    printf("%c ", P[idx].info); // Mengunjungi orang tua
}

void Postorder(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Pohon kosong\n");
        return;
    }
    Postorder_recursive(P, 1);
    printf("\n");
}

/* Penelusuran Level-order menggunakan antrian */
void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) {
        printf("Pohon kosong\n");
        return;
    }

    address queue[jml_maks];
    int front = 0, rear = 0;

    queue[rear++] = 1; // Mulai dari akar
    while (front < rear && rear <= Maks_node) {
        address curr = queue[front++];
        if (curr == nil || X[curr].info == '\0') continue;

        printf("%c ", X[curr].info);

        // Masukkan anak pertama ke antrian
        if (X[curr].ps_fs != nil) {
            queue[rear++] = X[curr].ps_fs;
        }

        // Masukkan saudara ke antrian
        address sibling = X[curr].ps_fs;
        while (sibling != nil) {
            if (X[sibling].ps_nb != nil) {
                queue[rear++] = X[sibling].ps_nb;
            }
            sibling = X[sibling].ps_nb;
        }
    }
    printf("\n");
}

/* Mencetak Pohon dengan indentasi untuk menunjukkan hierarki */
void PrintTree_recursive(Isi_Tree P, address idx, int level) {
    if (idx == nil || P[idx].info == '\0') return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%c\n", P[idx].info);
    PrintTree_recursive(P, P[idx].ps_fs, level + 1);
    PrintTree_recursive(P, P[idx].ps_nb, level);
}

void PrintTree(Isi_Tree P) {
    if (IsEmpty(P)) {
        printf("Pohon kosong\n");
        return;
    }
    PrintTree_recursive(P, 1, 0);
}

/* Mencari node dengan nilai X */
bool Search_recursive(Isi_Tree P, address idx, infotype X) {
    if (idx == nil || P[idx].info == '\0') return false;
    if (P[idx].info == X) return true;
    return Search_recursive(P, P[idx].ps_fs, X) || Search_recursive(P, P[idx].ps_nb, X);
}

bool Search(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return false;
    return Search_recursive(P, 1, X);
}

/* Menghitung jumlah total node */
int nbElmt_recursive(Isi_Tree P, address idx) {
    if (idx == nil || P[idx].info == '\0') return 0;
    return 1 + nbElmt_recursive(P, P[idx].ps_fs) + nbElmt_recursive(P, P[idx].ps_nb);
}

int nbElmt(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    return nbElmt_recursive(P, 1);
}

/* Menghitung jumlah node daun */
int nbDaun_recursive(Isi_Tree P, address idx) {
    if (idx == nil || P[idx].info == '\0') return 0;
    if (P[idx].ps_fs == nil) return 1; // Daun jika tidak punya anak pertama
    return nbDaun_recursive(P, P[idx].ps_fs) + nbDaun_recursive(P, P[idx].ps_nb);
}

int nbDaun(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    return nbDaun_recursive(P, 1);
}

/* Menemukan level node X */
int Level_recursive(Isi_Tree P, address idx, infotype X) {
    if (idx == nil || P[idx].info == '\0') return -1;
    if (P[idx].info == X) return 0;
    int level_fs = Level_recursive(P, P[idx].ps_fs, X);
    if (level_fs != -1) return level_fs + 1;
    int level_nb = Level_recursive(P, P[idx].ps_nb, X);
    if (level_nb != -1) return level_nb;
    return -1;
}

int Level(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return -1;
    int level = Level_recursive(P, 1, X);
    return level == -1 ? -1 : level;
}

/* Menghitung tinggi (depth) pohon */
int Depth_recursive(Isi_Tree P, address idx) {
    if (idx == nil || P[idx].info == '\0') return -1;
    int max_depth = -1;
    address child = P[idx].ps_fs;
    while (child != nil) {
        int child_depth = Depth_recursive(P, child);
        if (child_depth > max_depth) max_depth = child_depth;
        child = P[child].ps_nb;
    }
    return max_depth + 1;
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    return Depth_recursive(P, 1) + 1;
}

/* Mengembalikan nilai maksimum dari dua data */
int Max(infotype Data1, infotype Data2) {
    return Data1 > Data2 ? Data1 : Data2;
}