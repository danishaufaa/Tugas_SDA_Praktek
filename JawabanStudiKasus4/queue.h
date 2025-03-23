#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"  

typedef struct {
    char nama[50];
    char kendaraan[50];
    char tanggalSewa[20];
    double biayaSewa;
} Pelanggan;

typedef struct {
    Node* front;  
    Node* rear;   
} Queue;

void initQueue(Queue* queue);

int isEmptyQueue(Queue* queue);

void enqueue(Queue* queue, Pelanggan* p);

Pelanggan* dequeue(Queue* queue);

Pelanggan* peekQueue(Queue* queue);

#endif 
