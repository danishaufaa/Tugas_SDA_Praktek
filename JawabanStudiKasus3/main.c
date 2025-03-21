#include "queue.h"
#include <stdio.h>

int main() {
    MultiQueue mq;
    initializeMultiQueue(&mq);
    int choice;

    do {
        printHeader("Menu Antrian Bank");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Keluar\n");
        printf("\nPilihan : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printHeader("Ambil Antrian");
                enqueueMulti(&mq);
                printMultiQueue(&mq);
                break;
            case 2:
                printHeader("Proses Antrian");
                dequeueMulti(&mq);
                printMultiQueue(&mq);
                break;
            case 3:
                printHeader("Cetak Antrian");
                printMultiQueue(&mq);
                break;
            case 4:
                printHeader("Keluar dari Program");
                printf("Terima kasih telah menggunakan layanan kami.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 4);

    return 0;
}