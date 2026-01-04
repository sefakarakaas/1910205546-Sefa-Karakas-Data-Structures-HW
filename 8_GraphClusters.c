#include <stdio.h>
#include <stdbool.h>

#define V 6

int adjMatrix[V][V] = {
    {0, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0}
};

bool seen[V];

void findCluster(int u) {
    seen[u] = true;
    printf("%d ", u);
    for (int v = 0; v < V; v++) {
        if (adjMatrix[u][v] == 1 && !seen[v]) {
            findCluster(v);
        }
    }
}

int main() {
    for (int i = 0; i < V; i++) seen[i] = false;

    int cNum = 1;
    printf("Graph Clusters (Connected Components):\n");
    
    for (int i = 0; i < V; i++) {
        if (!seen[i]) {
            printf("Cluster %d: { ", cNum++);
            findCluster(i);
            printf("}\n");
        }
    }
    return 0;
}