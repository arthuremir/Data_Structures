#ifndef BFSQUEUE_MIDDLESTACK_H
#define BFSQUEUE_MIDDLESTACK_H

#endif

#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} node;

typedef struct stack {
    struct node *head, *mid;
    int count;
} stack;

stack *createStack(void) {
    stack *head = malloc(sizeof(stack));
    head->head = NULL;
    head->mid = NULL;
    head->count = 0;
    return head;
}

node *createNode(int data, node *next, node *prev) {
    node *node = malloc(sizeof(node));
    node->prev = prev;
    node->next = next;
    node->data = data;
    return node;
}

void push(stack *s,int data){
    node *new_node = createNode(data,s->head,NULL);
    s->count++;
    if(s->count==1){
        s->mid = new_node;
    } else {
        s->head->prev = new_node;
        if(s->count&1){
            s->mid = s->mid->prev;
        }
    }
    s->head = new_node;
}

int pop(stack *s){
    if(s->count!=0){
        node *tmp = s->head;
        int data = s->head->data;
        s->count--;
        if(s->count&1){
            s->mid = s->mid->next;
        }
        if(s->head!=NULL) {
            s->head = s->head->next;
            s->head->prev = NULL;
        }
        free(tmp);
        return data;
    } else {
        return INT_MIN;
    }
}

void printList(node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}



































