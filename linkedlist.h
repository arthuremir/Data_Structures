#ifndef BFSQUEUE_LINKEDLIST_H
#define BFSQUEUE_LINKEDLIST_H

#endif //BFSQUEUE_LINKEDLIST_H

#include <stdlib.h>

typedef struct listNode {
    int key;
    struct listNode *next, *prev;
} node;

node *createNode(int key, node *prev, node *next) {
    node *new_node = malloc(sizeof(node));
    new_node->next = next;
    new_node->prev = prev;
    new_node->key = key;
    return new_node;
}

void insertNode(node **head, int key) {
    if (*head == NULL) {
        *head = createNode(key, NULL, NULL);
    } else {
        node *new_node = createNode(key, NULL, *head);
        (*head)->prev = new_node;
        *head = new_node;
    }
}

void printList(node *list) {
    printf("\n");
    while (list != NULL) {
        printf("%d ", list->key);
        list = list->next;
    }
    printf("\n");
}

void deleteList(node *list) {
    node *tmp = NULL;
    while (list != NULL) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
}

node *deleteK(node *head, int K) {
    if (K == 0) return head;
    node *tmp = head;
    node *prev = NULL;
    int x = 1;
    while (tmp != NULL) {
        if (x % K == 0) {
            if (prev == NULL) {
                prev = tmp;
                tmp = tmp->next;
                free(prev);
                prev = NULL;
                head = NULL;
            } else {
                node *next = tmp->next;
                prev->next = next;
                free(tmp);
                tmp = next;
            }
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
        x++;
    }
    return head;
}

node *reverseList(node *list) {
    node *prev = NULL, *curr = list, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node *insertMid(node *list, int key) {
    if (list == NULL) {
        return createNode(key, NULL, NULL);
    }
    node *slow = NULL, *fast = list;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            if (slow != NULL) {
                slow = slow->next;
            } else {
                slow = list;
            }

        }
    }
    node *next = slow->next;
    node *new_node = createNode(key, slow, next);
    next->prev = new_node;
    slow->next = new_node;
    return list;
}

node *rotateK(node *list, int K) {
    node *head = list;
    node *tail = list;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    //printf("\n%d\n",tail->key);
    for (int i = 0; i < K; i++) {
        node *new_head = head->next;
        tail->next = head;
        head->prev = tail;
        head->next = NULL;
        new_head->prev = NULL;
        head = new_head;
        tail = tail->next;
    }
    return head;
}

node *findMid(node *list) {
    node *tortoise = list, *hare = list->next;
    while (hare && hare->next) {
        hare = hare->next->next;
        tortoise = tortoise->next;
    }
    return tortoise;
}

void reverse(node **list) {
    node *prev = NULL;
    node *curr = *list;
    node *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *list = prev;
}

void mergeLists(node **list1, node *list2) {
    node *prev2 = NULL;
    node *node1 = *list1;
    node *node2 = list2;
    node *next1 = NULL;
    node *next2 = NULL;
    while (node1 && node2) {
        next1 = node1->next;
        next2 = node2->next;
        node1->next = node2;
        node2->next = next1;
        prev2 = node2;
        node1 = next1;
        node2 = next2;
    }
    if (!node1 && node2) {
        prev2->next = node2;
    }
}

void rearrange(node **list) {
    node *list1 = *list;
    node *list2 = findMid(list1);
    node *tmp = list2;
    list2 = list2->next;
    tmp->next = NULL;
    reverse(&list2);
    mergeLists(&list1, list2);
}

/*void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[],int l,int h){
    int x = arr[h];
    int i = l-1;
    for(int j = l;j<h;j++){
        if(arr[j]<x){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[h],&arr[i+1]);
    return i+1;
}

void quicksort(int arr[],int l,int h){
    if(l<h){
        int p = partition(arr,l,h);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,h);
    }
}*/

void swap(node *a,node *b){
    int t = b->key;
    b->key = a->key;
    a->key = t;
}


node *partition(node *l, node *h) {
    int pivot = h->key;
    node *curr = l->prev;

    for (node *t = l; t != h; t = t->next) {
        if(t->key<=pivot){
            curr = (curr==NULL)?(l):(curr->next);
            swap(curr,t);
        }
    }
    curr = (curr==NULL)?(l):(curr->next);
    swap(h,curr);
    return curr;
}


void _quicksort(node *l, node *h) {
    if (h != NULL && l != h && l != h->next) {
        node *p = partition(l, h);
        _quicksort(l, p->prev);
        _quicksort(p->next, h);
    }
}


void quicksort(node *list) {
    node *l = list;
    while (l->next) l = l->next;
    _quicksort(list, l);
}






















