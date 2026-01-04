#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 100

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void push(char s[], int *top, char v) {
    s[++(*top)] = v;
}

char pop(char s[], int *top) {
    return s[(*top)--];
}

void toPostfix(char infix[], char postfix[]) {
    char stack[STACK_SIZE];
    int top = -1;
    int k = 0, len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[k++] = token;
        } 
        else if (token == '(') {
            push(stack, &top, token);
        } 
        else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop(stack, &top);
            }
            pop(stack, &top);
        } 
        else {
            while (top != -1 && priority(stack[top]) >= priority(token)) {
                postfix[k++] = pop(stack, &top);
            }
            push(stack, &top, token);
        }
    }

    while (top != -1) {
        postfix[k++] = pop(stack, &top);
    }
    postfix[k] = '\0';
}

int main() {
    char input[] = "(K+L)*(M-N)";
    char output[STACK_SIZE];
    
    toPostfix(input, output);
    
    printf("Infix: %s\n", input);
    printf("Postfix: %s\n", output);
    return 0;
}