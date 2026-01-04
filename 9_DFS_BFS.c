#include <stdio.h>
#include <stdbool.h>

#define NODES 5

int graph[NODES][NODES] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0}
};

bool visitedDFS[NODES] = {0};

void runDFS(int u) {
    visitedDFS[u] = true;
    printf("%d ", u);
    for (int v = 0; v < NODES; v++) {
        if (graph[u][v] && !visitedDFS[v]) runDFS(v);
    }
}

void runBFS(int start) {
    bool visitedBFS[NODES] = {0};
    int queue[NODES], f = 0, r = 0;

    visitedBFS[start] = true;
    queue[r++] = start;

    while (f < r) {
        int curr = queue[f++];
        printf("%d ", curr);

        for (int i = 0; i < NODES; i++) {
            if (graph[curr][i] && !visitedBFS[i]) {
                visitedBFS[i] = true;
                queue[r++] = i;
            }
        }
    }
}

int main() {
    printf("DFS Traversal: ");
    runDFS(0);
    
    printf("\nBFS Traversal: ");
    runBFS(0);
    printf("\n");
    
    return 0;
}