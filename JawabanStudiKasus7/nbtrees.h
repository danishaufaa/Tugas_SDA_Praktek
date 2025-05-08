#ifndef nbtrees_h
#define nbtrees_h

#include <stdbool.h>

// Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

// Arah traversal
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0

/* Type data */
/* Index dalam bahasa C dimulai dengan 0; tetapi indeks 0 tidak dipakai */
/* Kamus */
typedef char infotype;
typedef int address;
typedef struct {
    infotype info;
    address ps_fs;  /* Anak pertama */
    address ps_nb;  /* Saudara berikutnya */
    address ps_pr;  /* Orang tua */
} nbtree;

typedef nbtree Isi_Tree[jml_maks+1];

/* S P E S I F I K A S I */
void Create_tree(Isi_Tree X, int Jml);
/* Membuat Pohon Non Biner sebanyak Jml Node */
/* Tujuan mengentrykan Pohon Non Biner ke array Isi_Tree dengan pola Level Order */
/* Jml Node adalah banyaknya elemen dalam Pohon yang menjadi parameter input */

bool IsEmpty(Isi_Tree P);
/* Mengirimkan true jika Isi_Tree KOSONG */

/* Penelusuran */
void Preorder(Isi_Tree P);
/* Penelusuran Preorder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Preorder : Parent, fs, nb */

void Inorder(Isi_Tree P);
/* Penelusuran Inorder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Inorder : fs, Parent, Sisa anak lain */

void Postorder(Isi_Tree P);
/* Penelusuran Postorder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Postorder : fs, nb, Parent */

void Level_order(Isi_Tree X, int Maks_node);
/* Penelusuran Levelorder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level order */

void PrintTree(Isi_Tree P);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */

/* Pencarian */
bool Search(Isi_Tree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* Fungsi Lain */
int nbElmt(Isi_Tree P);
/* Mengirimkan banyak elemen (node) di pohon non biner P */

int nbDaun(Isi_Tree P);
/* Mengirimkan banyak daun (node) pohon non biner P */

int Level(Isi_Tree P, infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul */
/* dari pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */

int Depth(Isi_Tree P);
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */

int Max(infotype Data1, infotype Data2);
/* Mengirimkan Nilai terbesar dari dua data */

#endif