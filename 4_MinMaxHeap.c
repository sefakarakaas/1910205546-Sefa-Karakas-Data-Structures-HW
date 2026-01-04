#include <stdio.h>

void swap(int *x, int *y) {
    int t = *x; *x = *y; *y = t;
}

void heapifyMax(int arr[], int n, int i) {
    int lg = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[lg]) lg = l;
    if (r < n && arr[r] > arr[lg]) lg = r;

    if (lg != i) {
        swap(&arr[i], &arr[lg]);
        heapifyMax(arr, n, lg);
    }
}

void heapifyMin(int arr[], int n, int i) {
    int sm = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[sm]) sm = l;
    if (r < n && arr[r] < arr[sm]) sm = r;

    if (sm != i) {
        swap(&arr[i], &arr[sm]);
        heapifyMin(arr, n, sm);
    }
}

void buildMax(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapifyMax(arr, n, i);
}

void buildMin(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapifyMin(arr, n, i);
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int d1[] = {12, 11, 13, 5, 6, 7};
    int d2[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    buildMax(d1, n);
    printf("Max Heap: ");
    display(d1, n);

    buildMin(d2, n);
    printf("Min Heap: ");
    display(d2, n);

    return 0;
}