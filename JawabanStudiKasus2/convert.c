#include "convert.h"

void decimalToBinary(int decimal, Stack* stack) {
    initializeList(stack); 
    while (decimal > 0) {
        push(stack, decimal % 2);
        decimal /= 2;
    }
}
