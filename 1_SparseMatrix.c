#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} Element;

int main() {
    int m = 5, n = 5;
    int matrix[5][5] = {
        {0, 0, 0, 0, 9},
        {0, 5, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 7, 0},
        {0, 0, 0, 0, 0}
    };

    int count = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != 0) count++;
        }
    }

    Element* sparse = (Element*)malloc((count + 1) * sizeof(Element));

    sparse[0].row = m;
    sparse[0].col = n;
    sparse[0].val = count;

    int index = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != 0) {
                sparse[index].row = i;
                sparse[index].col = j;
                sparse[index].val = matrix[i][j];
                index++;
            }
        }
    }

    printf("Row\tCol\tValue\n");
    for(int i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].val);
    }

    free(sparse);
    return 0;
}