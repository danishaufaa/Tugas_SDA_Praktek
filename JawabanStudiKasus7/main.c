#include <stdio.h>
#include "nbtrees.h"

int main() {
    Isi_Tree pohon;
    infotype cari;
    int jumlah_node = 8; // Diperbarui menjadi 8 untuk mencocokkan Gambar 18 hingga level 2

    printf("=== Pengujian ADT Pohon Non-Biner ===\n\n");

    // Menguji Create_tree dan IsEmpty
    printf("Membuat pohon dengan %d node...\n", jumlah_node);
    Create_tree(pohon, jumlah_node);
    if (IsEmpty(pohon)) {
        printf("Pohon kosong.\n");
    } else {
        printf("Pohon berhasil dibuat.\n");
    }
    printf("\n");

    // Menguji PrintTree
    printf("Struktur Pohon:\n");
    PrintTree(pohon);
    printf("\n");

    // Menguji penelusuran
    printf("Penelusuran Preorder:\n");
    Preorder(pohon);
    printf("\n");

    printf("Penelusuran Inorder:\n");
    Inorder(pohon);
    printf("\n");

    printf("Penelusuran Postorder:\n");
    Postorder(pohon);
    printf("\n");

    printf("Penelusuran Level-order:\n");
    Level_order(pohon, jml_maks);
    printf("\n");

    // Menguji Search
    cari = 'C';
    printf("Mencari node '%c': %s\n", cari, Search(pohon, cari) ? "Ditemukan" : "Tidak ditemukan");
    cari = 'Z';
    printf("Mencari node '%c': %s\n", cari, Search(pohon, cari) ? "Ditemukan" : "Tidak ditemukan");
    printf("\n");

    // Menguji nbElmt
    printf("Jumlah total node: %d\n", nbElmt(pohon));
    printf("\n");

    // Menguji nbDaun
    printf("Jumlah node daun: %d\n", nbDaun(pohon));
    printf("\n");

    // Menguji Level
    cari = 'D';
    int level = Level(pohon, cari);
    if (level != -1) {
        printf("Level node '%c': %d\n", cari, level);
    } else {
        printf("Node '%c' tidak ditemukan.\n", cari);
    }
    printf("\n");

    // Menguji Depth
    printf("Tinggi pohon: %d\n", Depth(pohon));
    printf("\n");

    // Menguji Max
    infotype a = 'A', b = 'B';
    printf("Nilai maksimum antara '%c' dan '%c': %c\n", a, b, Max(a, b));

    printf("=== Pengujian Selesai ===\n");

    return 0;
}