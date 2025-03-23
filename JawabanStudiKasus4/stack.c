#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// Fungsi untuk inisialisasi stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmptyStack(Stack* stack) {
    return stack->top == NULL;
}

// Fungsi untuk menambahkan transaksi ke stack
void push(Stack* stack, Transaksi* t) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    // Tidak menggunakan 'data', kita menyimpan pointer ke transaksi di node
    newNode->next = stack->top;
    newNode->next = (void*)t;  // Menyimpan pointer ke transaksi di node
    stack->top = newNode;
}

// Fungsi untuk menghapus transaksi dari stack
Transaksi* pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack is empty!\n");
        exit(1);  // Jika stack kosong, hentikan program
    }
    Node* temp = stack->top;
    Transaksi* t = (Transaksi*)temp->next;
    stack->top = stack->top->next;
    free(temp);
    return t;
}

Transaksi* peek(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Stack is empty!\n");
        exit(1);  
    }
    return (Transaksi*)stack->top->next;
}
