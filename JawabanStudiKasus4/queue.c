#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmptyQueue(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, Pelanggan* p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->next = NULL;
    newNode->next = (void*)p;  

    if (isEmptyQueue(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Pelanggan* dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty!\n");
        exit(1);  
    }
    Node* temp = queue->front;
    Pelanggan* p = (Pelanggan*)temp->next;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return p;
}

Pelanggan* peekQueue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty!\n");
        exit(1);  
    }
    return (Pelanggan*)queue->front->next;
}
