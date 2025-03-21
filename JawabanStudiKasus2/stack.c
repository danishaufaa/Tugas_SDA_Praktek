#include "stack.h"

void push(Stack* stack, int data) {
    char temp[10]; 
    sprintf(temp, "%d", data);
    insertFirst(stack, temp, 0); 
}

int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    
    int data = atoi(stack->head->nama); 
    deleteFirst(stack);
    return data;
}

int isEmpty(Stack* stack) {
    return stack->head == NULL;
}
