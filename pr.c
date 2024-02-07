#include <stdio.h>
#include <limits.h>

#define MAX 10

int graph[MAX][MAX];
int parent[MAX];
int key[MAX];
int visited[MAX];

int n; // Number of vertices

// Function to find the vertex with the minimum key value
int minKey() {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the minimum spanning tree
void printMST() {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's algorithm
void prim() {
    // Initialize key values and visited array
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0; // Start with the first vertex
    parent[0] = -1; // No parent for the first vertex

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(); // Pick the minimum key vertex from the set of vertices not yet included in MST
        visited[u] = 1; // Mark the picked vertex as visited

        // Update key values and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST();
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge, weight otherwise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nMinimum Spanning Tree using Prim's Algorithm:\n");
    prim();

    return 0;
}
