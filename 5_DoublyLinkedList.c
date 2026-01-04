#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *prev, *next;
} Node;

Node* newNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->prev = n->next = NULL;
    return n;
}

void append(Node** head, int v) {
    Node* n = newNode(v);
    if (!*head) {
        *head = n;
        return;
    }
    Node* t = *head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void insertMid(Node* head, int after, int v) {
    Node* t = head;
    while (t && t->val != after) t = t->next;
    if (!t) return;
    
    Node* n = newNode(v);
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
}

void deleteNode(Node** head, int v) {
    Node* t = *head;
    while (t && t->val != v) t = t->next;
    if (!t) return;

    if (t->prev) t->prev->next = t->next;
    else *head = t->next;

    if (t->next) t->next->prev = t->prev;
    free(t);
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* root = NULL;
    append(&root, 10);
    append(&root, 20);
    append(&root, 30);
    
    printf("List: ");
    printList(root);

    insertMid(root, 20, 25);
    printf("Inserted 25: ");
    printList(root);

    deleteNode(&root, 10);
    printf("Deleted 10: ");
    printList(root);
    return 0;
}