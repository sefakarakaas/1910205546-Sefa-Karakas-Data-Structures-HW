#include <stdio.h>

int insert(int arr[], int n, int cap, int pos, int val) {
    if (n >= cap || pos < 0 || pos > n) return n;
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    return n + 1;
}

int delete(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) return n;
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    return n - 1;
}

void show(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[10] = {1, 2, 4, 5};
    int size = 4;

    printf("Start: ");
    show(arr, size);

    size = insert(arr, size, 10, 2, 3);
    printf("Added 3 at index 2: ");
    show(arr, size);

    size = delete(arr, size, 0);
    printf("Deleted index 0: ");
    show(arr, size);

    return 0;
}