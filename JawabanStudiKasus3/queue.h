#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

#define MAX_QUEUE_SIZE 5

typedef struct Queue {
    LinkedList list;
    int count;
    struct Queue* next;
} Queue;

typedef struct {
    Queue* head;
    int queueCount;
} MultiQueue;

void initializeMultiQueue(MultiQueue* mq);
void enqueueMulti(MultiQueue* mq);
void dequeueMulti(MultiQueue* mq);
void printMultiQueue(MultiQueue* mq);
void printHeader(const char* title);

#endif