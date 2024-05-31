#include <stdio.h>
#include <stdbool.h>

#define INT_MAX 1000

void printMST(int parent[], int graph[][INT_MAX], int edges) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < edges; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

int minKey(int key[], bool mstSet[], int edges) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < edges; v++) {
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    }
    return min_index;
}

void primMST(int graph[][INT_MAX], int edges) {
    int parent[edges], key[edges];
    bool mstSet[edges];
    for (int i = 0; i < edges; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < edges - 1; count++) {
        int u = minKey(key, mstSet, edges);
        mstSet[u] = true;

        for (int v = 0; v < edges; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
    }
    printMST(parent, graph, edges);
}

int main() {
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    int graph[edges][INT_MAX];
    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < edges; i++) {
        for (int j = 0; j < edges; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    primMST(graph, edges);
    return 0;
}

