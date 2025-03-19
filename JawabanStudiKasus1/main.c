#include "linked_list.h"

int main() {
    LinkedList L1, L2;
    initializeList(&L1);
    initializeList(&L2);

    insertSorted(&L1, "Budi", 85);
    insertSorted(&L1, "Alya", 90);
    insertSorted(&L1, "Citra", 60);
    insertSorted(&L1, "Deni", 75);
    insertSorted(&L1, "Alya", 95);
    insertSorted(&L1, "Cantika", 65);
    insertSorted(&L1, "Aufa", 100);
    insertSorted(&L1, "Danish", 89);
    insertSorted(&L1, "Hanifa", 98);

    printf("\nList L1 (Mengurutkan Berdasarkan Nama):\n");
    printAscending(&L1);
    
    printf("\nList L1 (Mengurutkan Berdasarkan Nilai UTS):\n");
    printDescending(&L1);

    printf("\nJumlah mahasiswa di L1: %d\n\n", countElements(&L1));

    copyAbove70(&L1, &L2);
    printf("\nList L2 (Memindahkan Yang Diatas Nilai 70):\n");
    printAscending(&L2);

    removeDuplicates(&L2);
    printf("\nList L2 (Menghapus Nama Yang Sama):\n");
    printAscending(&L2);

    clearList(&L1);
    clearList(&L2);

    return 0;
}