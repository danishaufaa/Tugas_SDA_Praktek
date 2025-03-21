#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int globalCustomerNumber = 1;

void initializeMultiQueue(MultiQueue* mq) {
    mq->head = (Queue*)malloc(sizeof(Queue));
    initializeList(&mq->head->list);
    mq->head->count = 0;
    mq->head->next = NULL;
    mq->queueCount = 1;
}

void enqueueMulti(MultiQueue* mq) {
    Queue* current = mq->head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->count >= MAX_QUEUE_SIZE) {
        current->next = (Queue*)malloc(sizeof(Queue));
        initializeList(&current->next->list);
        current->next->count = 0;
        current->next->next = NULL;
        mq->queueCount++;
        current = current->next;
    }

    char nama[26];
    printf("Masukkan nama pelanggan (Maksimal 25 karakter) : ");
    scanf(" %25[^\n]", nama); 
    
    insertLast(&current->list, nama, current->count + 1);
    current->count++;
}

void dequeueMulti(MultiQueue* mq) {
    if (mq->head == NULL) {
        printf("Antrian kosong!\n");
        return;
    }

    Queue* current = mq->head;
    int queueIndex = 1;
    while (current != NULL) {
        if (current->list.head != NULL) {
            printf("Counter %d Melayani : %s\n", queueIndex, current->list.head->nama);
            deleteFirst(&current->list);
            current->count--;
        }
        current = current->next;
        queueIndex++;
    }

    while (mq->head != NULL && mq->head->count == 0 && mq->head->next != NULL) {
        Queue* temp = mq->head;
        mq->head = mq->head->next;
        free(temp);
        mq->queueCount--;
    }
}

void printMultiQueue(MultiQueue* mq) {
    Queue* current = mq->head;
    int index = 1;
    while (current != NULL) {
        printf("Counter %d :\n", index++);
        displayList(&current->list);
        current = current->next;
    }
}

void printHeader(const char* title) {
    printf("\n===========================\n");
    printf("%s\n", title);
    printf("===========================\n");
}