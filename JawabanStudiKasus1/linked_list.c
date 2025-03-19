// linked_list.c
#include "linked_list.h"

// Inisialisasi list
void initializeList(LinkedList* list) {
    list->head = NULL;
}

// Menyisipkan elemen ke dalam list secara ascending berdasarkan nama
void insertSorted(LinkedList* list, char* nama, int nilaiUTS) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->nama, nama);
    newNode->nilaiUTS = nilaiUTS;
    newNode->next = NULL;

    if (list->head == NULL || strcmp(list->head->nama, nama) > 0) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && strcmp(current->next->nama, nama) < 0) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Menampilkan list dalam urutan ascending berdasarkan nama
void printAscending(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%s - %d\n", temp->nama, temp->nilaiUTS);
        temp = temp->next;
    }
}

// Menampilkan list dalam urutan descending berdasarkan nilai UTS
void printDescending(LinkedList* list) {
    int count = countElements(list);
    if (count == 0) return;

    // Simpan elemen ke dalam array sementara
    Node* temp = list->head;
    Node* arr[count];
    int i = 0;

    while (temp != NULL) {
        arr[i++] = temp;
        temp = temp->next;
    }

    // Bubble sort (descending)
    for (int j = 0; j < count - 1; j++) {
        for (int k = 0; k < count - j - 1; k++) {
            if (arr[k]->nilaiUTS < arr[k + 1]->nilaiUTS) {
                Node* swap = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = swap;
            }
        }
    }

    // Cetak hasil sorting
    for (i = 0; i < count; i++) {
        printf("%s - %d\n", arr[i]->nama, arr[i]->nilaiUTS);
    }
}

// Menghitung jumlah elemen dalam list
int countElements(LinkedList* list) {
    int count = 0;
    Node* temp = list->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Menyalin elemen dengan nilai UTS > 70 ke List L2
void copyAbove70(LinkedList* source, LinkedList* dest) {
    Node* temp = source->head;
    while (temp != NULL) {
        if (temp->nilaiUTS > 70) {
            printf("Menyalin dan Memindahkan %s - %d ke L2\n", temp->nama, temp->nilaiUTS); // Debugging
            insertSorted(dest, temp->nama, temp->nilaiUTS);
        }
        temp = temp->next;
    }
}

// Menghapus duplikasi nama dari list
void removeDuplicates(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL && current->next != NULL) {
        Node* prev = current;
        Node* temp = current->next;
        while (temp != NULL) {
            if (strcmp(current->nama, temp->nama) == 0) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

// Menghapus seluruh elemen dalam list
void clearList(LinkedList* list) {
    Node* temp;
    while (list->head != NULL) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}