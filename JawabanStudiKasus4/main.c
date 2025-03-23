#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

int main() {
    Stack transaksiStack;
    initStack(&transaksiStack);

    Queue pelangganQueue;
    initQueue(&pelangganQueue);

    Transaksi* t = (Transaksi*)malloc(sizeof(Transaksi));  
    t->idTransaksi = 1;
    snprintf(t->tanggal, sizeof(t->tanggal), "2025-03-23");
    snprintf(t->kendaraan, sizeof(t->kendaraan), "Toyota");
    t->biayaSewa = 150000;
    push(&transaksiStack, t);  

    Pelanggan* p = (Pelanggan*)malloc(sizeof(Pelanggan));  
    snprintf(p->nama, sizeof(p->nama), "John Doe");
    snprintf(p->kendaraan, sizeof(p->kendaraan), "Honda");
    snprintf(p->tanggalSewa, sizeof(p->tanggalSewa), "2025-03-23");
    p->biayaSewa = 200000;
    enqueue(&pelangganQueue, p);  
    
    Transaksi* tPop = pop(&transaksiStack);
    printf("Transaksi Pop: %d, %s, %s, %.2f\n", tPop->idTransaksi, tPop->tanggal, tPop->kendaraan, tPop->biayaSewa);

    Pelanggan* pDequeue = dequeue(&pelangganQueue);
    printf("Pelanggan Dequeue: %s, %s, %s, %.2f\n", pDequeue->nama, pDequeue->kendaraan, pDequeue->tanggalSewa, pDequeue->biayaSewa);

    free(t);
    free(p);

    return 0;
}
