#include <stdio.h>
#include "kota.h"

int main() {
    Kota daftarKota[MAX_KOTA];
    int jumlahKota = 0;
    int pilihan;
    char namaKota[50], namaOrang[50];
    
    initDaftarKota(daftarKota, MAX_KOTA);
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Nama di Kota\n");
        printf("3. Hapus Nama di Kota\n");
        printf("4. Hapus Kota\n");
        printf("5. Tampilkan Semua Kota\n");
        printf("6. Tampilkan Nama di Kota\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // hapus \n di buffer
        
        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0; // hapus newline
                tambahKota(daftarKota, &jumlahKota, namaKota);
                break;
            case 2:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama orang: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;
                {
                    int idx = cariKota(daftarKota, jumlahKota, namaKota);
                    if (idx != -1) {
                        tambahNamaDiKota(daftarKota, idx, namaOrang);
                    } else {
                        printf("Kota tidak ditemukan.\n");
                    }
                }
                break;
            case 3:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama orang yang ingin dihapus: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;
                {
                    int idx = cariKota(daftarKota, jumlahKota, namaKota);
                    if (idx != -1) {
                        hapusNamaDiKota(daftarKota, idx, namaOrang);
                    } else {
                        printf("Kota tidak ditemukan.\n");
                    }
                }
                break;
            case 4:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                hapusKota(daftarKota, &jumlahKota, namaKota);
                break;
            case 5:
                tampilkanSemuaKota(daftarKota, jumlahKota);
                break;
            case 6:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                {
                    int idx = cariKota(daftarKota, jumlahKota, namaKota);
                    if (idx != -1) {
                        printf("Daftar nama di kota %s:\n", namaKota);
                        tampilkanNamaDiKota(daftarKota, idx);
                    } else {
                        printf("Kota tidak ditemukan.\n");
                    }
                }
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);
    
    return 0;
}
