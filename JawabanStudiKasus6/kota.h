#ifndef KOTA_H
#define KOTA_H

#include "linked_list.h"

typedef struct NodeKota {
    char* namaKota;
    NodeString* listNamaOrang; 
    struct NodeKota* next;
} NodeKota;

// Fungsi-fungsi operasional
NodeKota* createNodeKota(const char* namaKota);
void insertKota(NodeKota** head, const char* namaKota);
void insertOrang(NodeKota* head, const char* namaKota, const char* namaOrang);
void tampilkanSemua(NodeKota* head);
void hapusOrang(NodeKota* head, const char* namaKota, const char* namaOrang);
void hapusKota(NodeKota** head, const char* namaKota);
void hapusSemua(NodeKota** head);

#endif
