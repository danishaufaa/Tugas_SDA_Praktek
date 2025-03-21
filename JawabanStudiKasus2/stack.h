#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

typedef LinkedList Stack;

void push(Stack* stack, int data);
int pop(Stack* stack);
int isEmpty(Stack* stack);

#endif
