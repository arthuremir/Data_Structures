#ifndef BFSQUEUE_AVLTREE_H
#define BFSQUEUE_AVLTREE_H
#endif

#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right, *parent;
} node;

node *create_node(int key, node *left, node *right, node *parent) {
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->left = left;
    new_node->right = right;
    new_node->parent = parent;
    return new_node;
}

node *insert(node *head, int key, node *parent) {
    if (head == NULL) return create_node(key, NULL, NULL, parent);
    if (key > head->key) {
        head->right = insert(head->right, key, head);
    } else if (key < head->key) {
        head->left = insert(head->left, key, head);
    }
    return head;
}

node *findNode(node *head, int key) {
    if (head) {
        if (key > head->key) {
            return findNode(head->right, key);
        } else if (key < head->key) {
            return findNode(head->left, key);
        } else {
            return head;
        }
    } else {
        return NULL;
    }
}

void printtree(node *node) {
    if (node) {
        printtree(node->left);
        printf("%d ", node->key);
        printtree(node->right);
    }
}

node *minNode(node *head) {
    if (head) {
        if (head->left) {
            return minNode(head->left);
        } else {
            return head;
        }
    }
    return head;
}

node *deleteNode(node *head, int key) {
    if (head == NULL) return head;
    if (key > head->key) {
        head->right = deleteNode(head->right, key);
    } else if (key < head->key) {
        head->left = deleteNode(head->left, key);
    } else {
        if (head->left == NULL) {
            node *tmp = head->right;
            free(head);
            return tmp;
        } else if (head->right == NULL) {
            node *tmp = head->left;
            free(head);
            return tmp;
        } else {
            node *tmp = minNode(head->right);
            head->key = tmp->key;
            head->right = deleteNode(head->right, tmp->key);
        }
    }
}





/*node *deleteNode(node *head, int key) {
    if (!head) return head;
    if (key > head->key) {
        head->right = deleteNode(head->right, key);
    } else if (key < head->key) {
        head->left = deleteNode(head->left, key);
    } else {
        if (!head->left) {
            node *tmp = head->right;
            free(head);
            return tmp;
        } else if (!head->right) {
            node *tmp = head->left;
            free(head);
            return tmp;
        } else {
            node *tmp = minNode(head->right);
            head->key = tmp->key;
            head->right = deleteNode(head->right, tmp->key);
        }
    }
    return head;
}*/ //delete

/*void insert(node **head, int key) {
    node *current = *head;
    node *prev = NULL;
    if (!current) {
        *head = create_node(key, NULL, NULL, NULL);
    } else {
        while (current) {
            prev = current;
            if (key > current->key) {
                current = current->right;
            } else if (key < current->key) {
                current = current->left;
            } else {
                break;
            }
        }
        if (!current && prev->key != key) {
            if (key > prev->key) {
                prev->right = create_node(key, NULL, NULL, prev);
            } else {
                prev->left = create_node(key, NULL, NULL, prev);
            }
        }
    }
}*/ //insertNonRec