#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100
#define INF 99999

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

int vertices, edges;
struct Edge edge[MAX_EDGES];
int distance[MAX_VERTICES];

// Function to perform Bellman-Ford algorithm
void bellmanFord(int source) {
    // Initialize distances to all vertices as infinity
    for (int i = 0; i < vertices; i++) {
        distance[i] = INF;
    }
    distance[source] = 0; // Distance from source to source is 0

    // Relax all edges |V| - 1 times
    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edge[j].source;
            int v = edge[j].destination;
            int weight = edge[j].weight;
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < edges; i++) {
        int u = edge[i].source;
        int v = edge[i].destination;
        int weight = edge[i].weight;
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Print the distances
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    printf("Enter source, destination, and weight for each edge:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &edge[i].source, &edge[i].destination, &edge[i].weight);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    bellmanFord(source);

    return 0;
}

