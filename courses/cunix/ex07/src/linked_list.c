#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *next;
} node_t;

node_t *list_create(void *data) {
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    head->data = data;
    head->next = NULL;

    return head;
}

void list_destroy(node_t **head, void(*fp)(void *data)) {
    struct node *tmp;
    tmp = (node_t *) malloc(sizeof(node_t));

    while(*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

void list_push(node_t **head, void *data) {
    while( (*head)->next == NULL ) {
        *head = (*head)->next;
    }
    node_t * newNode = NULL;
    newNode = (node_t *) malloc(sizeof(node_t));

    newNode->data = data;
    newNode->next = NULL;

    (*head)->next = newNode;
}

void list_unshift(node_t **head, char *key, void *data) {
    node_t * newNode = NULL;
    newNode = (node_t *) malloc(sizeof(node_t));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void *list_pop(node_t **head) {
    while( (*head)->next == NULL ) {
        *head = (*head)->next;
    }
    void * rt = (*head)->data;
    free(*head);
    return rt;
}

void *list_shift(node_t **head) {
    node_t * tmp = *head;
    *head = (*head)->next;
    void * rt = tmp->data;
    free(tmp);

    return rt;
}

void *list_remove(node_t **head, node_t *ptr) {
    node_t * prev = NULL;
    prev = (node_t *) malloc(sizeof(node_t));

    while(*head != NULL || *head != ptr) {
        prev = *head;
        *head = (*head)->next;
    }
    if(*head != NULL) {
        prev->next = (*head)->next;
        void * rt = (*head)->data;
        free(*head);

        return rt;
    }
    return NULL;
}

void list_print(node_t *head) {
    while(head != NULL) {
        printf("%p ", head->data);
        head = head->next;
    }
}

void list_visitor(node_t *head, void (*fp)(void *data)) {
    (*fp)(head->data);
}

