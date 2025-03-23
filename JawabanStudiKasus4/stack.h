#ifndef STACK_H
#define STACK_H

#include "linked_list.h"  

typedef struct {
    int idTransaksi;
    char tanggal[20];
    char kendaraan[50];
    double biayaSewa;
} Transaksi;

typedef struct {
    Node* top;  
} Stack;

void initStack(Stack* stack);

int isEmptyStack(Stack* stack);

void push(Stack* stack, Transaksi* t);

Transaksi* pop(Stack* stack);

Transaksi* peek(Stack* stack);

#endif 
