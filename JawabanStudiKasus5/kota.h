#ifndef KOTA_H
#define KOTA_H

#include "linked_list.h"

#define MAX_KOTA 5

typedef struct {
    char namaKota[50];
    NodeString* daftarNama;
} Kota;

void initDaftarKota(Kota daftarKota[], int ukuran);
int cariKota(Kota daftarKota[], int ukuran, const char* namaKota);
void tambahKota(Kota daftarKota[], int* jumlahKota, const char* namaKota);
void tambahNamaDiKota(Kota daftarKota[], int indexKota, const char* nama);
void hapusNamaDiKota(Kota daftarKota[], int indexKota, const char* nama);
void hapusKota(Kota daftarKota[], int* jumlahKota, const char* namaKota);
void tampilkanSemuaKota(Kota daftarKota[], int jumlahKota);
void tampilkanNamaDiKota(Kota daftarKota[], int indexKota);

#endif
