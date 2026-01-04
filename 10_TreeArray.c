#include <stdio.h>

#define MAX 20

char tree[MAX] = {'\0'};

void setRoot(char c) {
    tree[1] = c;
}

void setLeft(char c, int parent) {
    if (tree[parent] == '\0') return;
    tree[2 * parent] = c;
}

void setRight(char c, int parent) {
    if (tree[parent] == '\0') return;
    tree[2 * parent + 1] = c;
}

void printTree() {
    for (int i = 1; i < MAX; i++) {
        if (tree[i] != '\0') printf("Node %d: %c\n", i, tree[i]);
    }
}

int main() {
    setRoot('A');
    setLeft('B', 1);
    setRight('C', 1);
    setLeft('D', 2);
    setRight('E', 2);
    setRight('F', 3);

    printf("Binary Tree in Array:\n");
    printTree();
    return 0;
}