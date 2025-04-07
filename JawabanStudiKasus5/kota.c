#include "kota.h"

void initDaftarKota(Kota daftarKota[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        strcpy(daftarKota[i].namaKota, "");
        daftarKota[i].daftarNama = NULL;
    }
}

int cariKota(Kota daftarKota[], int ukuran, const char* namaKota) {
    for (int i = 0; i < ukuran; i++) {
        if (strcmp(daftarKota[i].namaKota, namaKota) == 0) {
            return i;
        }
    }
    return -1;
}

void tambahKota(Kota daftarKota[], int* jumlahKota, const char* namaKota) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("Kapasitas kota penuh!\n");
        return;
    }
    strcpy(daftarKota[*jumlahKota].namaKota, namaKota);
    daftarKota[*jumlahKota].daftarNama = NULL;
    (*jumlahKota)++;
}

void tambahNamaDiKota(Kota daftarKota[], int indexKota, const char* nama) {
    insertLastString(&daftarKota[indexKota].daftarNama, nama);
}

void hapusNamaDiKota(Kota daftarKota[], int indexKota, const char* nama) {
    deleteValueString(&daftarKota[indexKota].daftarNama, nama);
}

void hapusKota(Kota daftarKota[], int* jumlahKota, const char* namaKota) {
    int index = cariKota(daftarKota, *jumlahKota, namaKota);
    if (index == -1) {
        printf("Kota tidak ditemukan!\n");
        return;
    }
    deleteAllString(&daftarKota[index].daftarNama);

    // Geser data setelahnya
    for (int i = index; i < *jumlahKota - 1; i++) {
        daftarKota[i] = daftarKota[i + 1];
    }
    (*jumlahKota)--;
}

void tampilkanSemuaKota(Kota daftarKota[], int jumlahKota) {
    if (jumlahKota == 0) {
        printf("Belum ada data kota.\n");
        return;
    }
    for (int i = 0; i < jumlahKota; i++) {
        printf("Kota: %s\n", daftarKota[i].namaKota);
        tampilkanNamaDiKota(daftarKota, i);
        printf("\n");
    }
}

void tampilkanNamaDiKota(Kota daftarKota[], int indexKota) {
    NodeString* current = daftarKota[indexKota].daftarNama;
    int nomor = 1;
    if (current == NULL) {
        printf("  (Tidak ada nama)\n");
    } else {
        while (current != NULL) {
            printf("  %d. %s\n", nomor++, current->value);
            current = current->next;
        }
    }
}
