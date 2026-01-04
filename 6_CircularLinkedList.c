#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

CNode* create(int d) {
    CNode* n = (CNode*)malloc(sizeof(CNode));
    n->data = d;
    n->next = n;
    return n;
}

void add(CNode** head, int d) {
    CNode* n = create(d);
    if (!*head) {
        *head = n;
        return;
    }
    CNode* t = *head;
    while (t->next != *head) t = t->next;
    t->next = n;
    n->next = *head;
}

void insertAfter(CNode* head, int target, int d) {
    if (!head) return;
    CNode* t = head;
    do {
        if (t->data == target) {
            CNode* n = create(d);
            n->next = t->next;
            t->next = n;
            return;
        }
        t = t->next;
    } while (t != head);
}

void removeVal(CNode** head, int key) {
    if (!*head) return;
    CNode *curr = *head, *prev = NULL;
    
    while (curr->data != key) {
        if (curr->next == *head) return;
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == *head && prev == NULL) {
        *head = NULL;
        free(curr);
        return;
    }

    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) prev = prev->next;
        *head = curr->next;
        prev->next = *head;
    } else if (curr->next == *head) {
        prev->next = *head;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

void display(CNode* head) {
    if (!head) return;
    CNode* t = head;
    do {
        printf("%d -> ", t->data);
        t = t->next;
    } while (t != head);
    printf("HEAD\n");
}

int main() {
    CNode* start = NULL;
    add(&start, 1);
    add(&start, 2);
    add(&start, 3);

    display(start);
    
    insertAfter(start, 2, 99);
    display(start);

    removeVal(&start, 1);
    display(start);

    return 0;
}