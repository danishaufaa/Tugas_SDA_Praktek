#include "kota.h"

NodeKota* createNodeKota(const char* namaKota) {
    NodeKota* newNode = (NodeKota*)malloc(sizeof(NodeKota));
    newNode->namaKota = strdup(namaKota);
    newNode->listNamaOrang = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertKota(NodeKota** head, const char* namaKota) {
    NodeKota* newNode = createNodeKota(namaKota);
    if (*head == NULL) {
        *head = newNode;
    } else {
        NodeKota* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertOrang(NodeKota* head, const char* namaKota, const char* namaOrang) {
    NodeKota* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->namaKota, namaKota) == 0) {
            insertLastString(&(temp->listNamaOrang), namaOrang);
            return;
        }
        temp = temp->next;
    }
    printf("Kota %s tidak ditemukan.\n", namaKota);
}

void tampilkanSemua(NodeKota* head) {
    NodeKota* temp = head;
    while (temp != NULL) {
        printf("Kota: %s\n", temp->namaKota);
        NodeString* orang = temp->listNamaOrang;
        while (orang != NULL) {
            printf("  - %s\n", orang->value);
            orang = orang->next;
        }
        temp = temp->next;
    }
}

void hapusOrang(NodeKota* head, const char* namaKota, const char* namaOrang) {
    NodeKota* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->namaKota, namaKota) == 0) {
            deleteValueString(&(temp->listNamaOrang), namaOrang);
            return;
        }
        temp = temp->next;
    }
    printf("Kota %s tidak ditemukan.\n", namaKota);
}

void hapusKota(NodeKota** head, const char* namaKota) {
    if (*head == NULL) return;
    
    NodeKota* temp = *head;
    NodeKota* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->namaKota, namaKota) == 0) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            deleteAllString(&(temp->listNamaOrang));
            free(temp->namaKota);
            free(temp);
            printf("Kota %s berhasil dihapus.\n", namaKota);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Kota %s tidak ditemukan.\n", namaKota);
}

void hapusSemua(NodeKota** head) {
    NodeKota* temp = *head;
    while (temp != NULL) {
        NodeKota* next = temp->next;
        deleteAllString(&(temp->listNamaOrang));
        free(temp->namaKota);
        free(temp);
        temp = next;
    }
    *head = NULL;
    printf("Semua Data sudah Dihapus");
}
