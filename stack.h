#ifndef BFSQUEUE_STACK_H
#define BFSQUEUE_STACK_H

#endif //BFSQUEUE_STACK_H

#include <stdlib.h>


typedef struct stnode {
    int data;
    struct stnode *next;
} stnode;

stnode *createStnode(int data){
    stnode *new_node = malloc(sizeof(stnode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void printStack(stnode *stack){
    while(stack!=NULL){
        printf("%d ",stack->data);
        stack = stack->next;
    }
    printf("\n");
}

void push(stnode **stack,int data){
    stnode *new_node = createStnode(data);
    new_node->next = *stack;
    *stack = new_node;
    printStack(*stack);
}

int empty(stnode *stack){
    return (stack!=NULL)?0:1;
}

int pop(stnode **stack){
    if(!empty(*stack)) {
        stnode *node = *stack;
        *stack = (*stack)->next;
        int data = node->data;
        free(node);
        return data;
    }
    return INT_MIN;
}

int peek(stnode *stack){
    if(!empty(stack)){
        return stack->data;
    }
    return INT_MIN;
}



