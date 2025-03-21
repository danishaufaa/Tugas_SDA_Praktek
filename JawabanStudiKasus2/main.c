#include <stdio.h>
#include "convert.h"
#include "stack.h"

int main() {
    int decimal;
    Stack stack;
    initializeList(&stack); 

    printf("Masukkan Bilangan Desimal : ");
    scanf("%d", &decimal);

    decimalToBinary(decimal, &stack);

    printf("Bentuk Biner Dari Desimal Yang Dimasukkan : ");
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");

    return 0;
}
