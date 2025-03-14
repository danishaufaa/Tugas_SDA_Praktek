#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return NULL;
    }
    newNode->info = value;
    newNode->next = NULL;
    return newNode; 
}

void TampilkanList() {
    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }
    
    Node *q = head;
    printf("List saat ini : ");
    while (q != NULL) {
        printf("%d ", q->info);
        q = q->next;
    }
    printf("\n");
}

void insertFirst(int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) return;
    newNode->next = head;
    head = newNode;
    TampilkanList();
}

void insertLast(int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) return;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    TampilkanList();
}

void insertAfter(int target, int value) {
    Node* temp = head;
    while (temp != NULL && temp->info != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Elemen %d tidak ditemukan dalam list!\n", target);
        return;
    }
    Node* newNode = createNode(value);
    if (newNode == NULL) return;
    newNode->next = temp->next;
    temp->next = newNode;
    TampilkanList();
}

void deleteFirst() {
    if (head == NULL) {
        printf("List kosong! Tidak bisa menghapus elemen pertama.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    TampilkanList();
}

void deleteLast() {
    if (head == NULL) {
        printf("List kosong! Tidak bisa menghapus elemen terakhir.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    TampilkanList();
}

void deleteValue(int value) {
    if (head == NULL) {
        printf("List kosong! Tidak bisa menghapus elemen %d.\n", value);
        return;
    }
    if (head->info == value) {
        deleteFirst();
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->info != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Elemen %d tidak ditemukan dalam list!\n", value);
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    TampilkanList();
}

void deleteAll() {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Semua elemen telah dihapus.\n");
    TampilkanList();
}

int main() {
    insertFirst(7);
    insertLast(11);
    insertAfter(7, 9);
    insertFirst(5);
    insertLast(13);
    deleteLast();
    deleteValue(7);
    deleteFirst();
    deleteAll();

    return 0;
}
