#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Node untuk Mahasiswa
typedef struct Node {
    char nama[50];
    int nilaiUTS;
    struct Node* next;
} Node;

// Struktur List
typedef struct {
    Node* head;
} LinkedList;

// Deklarasi fungsi utama
void initializeList(LinkedList* list);
Node* createNode(char* nama, int nilaiUTS);
void insertSorted(LinkedList* list, char* nama, int nilaiUTS);
void printAscending(LinkedList* list);
void printDescending(LinkedList* list);
int countElements(LinkedList* list);
void copyAbove70(LinkedList* source, LinkedList* dest);
void removeDuplicates(LinkedList* list);
void clearList(LinkedList* list);

// Fungsi tambahan untuk manipulasi list
void insertFirst(LinkedList* list, char* nama, int nilaiUTS);
void insertLast(LinkedList* list, char* nama, int nilaiUTS);
void deleteFirst(LinkedList* list);
void deleteLast(LinkedList* list);
void deleteValue(LinkedList* list, char* nama);
void displayList(LinkedList* list);

#endif
