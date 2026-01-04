#include <stdio.h>

void solveHanoi(int n, char src, char dest, char aux) {
    if (n == 0) return;
    
    solveHanoi(n - 1, src, aux, dest);
    printf("Disk %d moved from %c to %c\n", n, src, dest);
    solveHanoi(n - 1, aux, dest, src);
}

int main() {
    int diskCount = 3;
    printf("Steps for %d disks:\n", diskCount);
    solveHanoi(diskCount, 'A', 'C', 'B');
    return 0;
}