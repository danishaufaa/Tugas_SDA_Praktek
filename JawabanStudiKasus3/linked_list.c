#include "linked_list.h"

// Inisialisasi list
void initializeList(LinkedList* list) {
    list->head = NULL;
}

// Membuat node baru
Node* createNode(char* nama, int nilaiUTS) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return NULL;
    }
    strcpy(newNode->nama, nama);
    newNode->nilaiUTS = nilaiUTS;
    newNode->next = NULL;
    return newNode;
}

// Menyisipkan elemen secara berurutan berdasarkan nama
void insertSorted(LinkedList* list, char* nama, int nilaiUTS) {
    Node* newNode = createNode(nama, nilaiUTS);
    if (newNode == NULL) return;

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

    Node* temp = list->head;
    Node* arr[count];
    int i = 0;

    while (temp != NULL) {
        arr[i++] = temp;
        temp = temp->next;
    }

    // Sorting secara descending berdasarkan nilai UTS
    for (int j = 0; j < count - 1; j++) {
        for (int k = 0; k < count - j - 1; k++) {
            if (arr[k]->nilaiUTS < arr[k + 1]->nilaiUTS) {
                Node* swap = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = swap;
            }
        }
    }

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

// Menyalin elemen dengan nilai UTS > 70 ke list lain
void copyAbove70(LinkedList* source, LinkedList* dest) {
    Node* temp = source->head;
    while (temp != NULL) {
        if (temp->nilaiUTS > 70) {
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

// Menampilkan isi list
void displayList(LinkedList* list) {
    if (list->head == NULL) {
        printf("List antrian kosong.\n");
        return;
    }

    Node* temp = list->head;
    printf("List antrian saat ini : ");
    while (temp != NULL) {
        printf("%s - %d ", temp->nama, temp->nilaiUTS);
        temp = temp->next;
    }
    printf("\n");
}

// Menambahkan node di awal list
void insertFirst(LinkedList* list, char* nama, int nilaiUTS) {
    Node* newNode = createNode(nama, nilaiUTS);
    if (newNode == NULL) return;
    newNode->next = list->head;
    list->head = newNode;
}

// Menambahkan node di akhir list
void insertLast(LinkedList* list, char* nama, int nilaiUTS) {
    Node* newNode = createNode(nama, nilaiUTS);
    if (newNode == NULL) return;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Menghapus elemen pertama
void deleteFirst(LinkedList* list) {
    if (list->head == NULL) return;
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

// Menghapus elemen terakhir
void deleteLast(LinkedList* list) {
    if (list->head == NULL) return;
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }
    Node* temp = list->head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Menghapus elemen berdasarkan nama
void deleteValue(LinkedList* list, char* nama) {
    if (list->head == NULL) return;
    if (strcmp(list->head->nama, nama) == 0) {
        deleteFirst(list);
        return;
    }
    Node* temp = list->head;
    while (temp->next != NULL && strcmp(temp->next->nama, nama) != 0) {
        temp = temp->next;
    }
    if (temp->next == NULL) return;
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}
