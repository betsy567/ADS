#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Maximum number of elements

typedef struct {
    int *parent;
    int *rank;
    int size;
} DisjointSet;

// Function prototypes
DisjointSet* createSet(int size);
int findSet(DisjointSet *set, int element);
void unionSets(DisjointSet *set, int element1, int element2);
void destroySet(DisjointSet *set);

// Function to create a disjoint set with 'size' elements
DisjointSet* createSet(int size) {
    DisjointSet *set = (DisjointSet*)malloc(sizeof(DisjointSet));
    set->size = size;
    set->parent = (int*)malloc(sizeof(int) * size);
    set->rank = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
}

// Function to find the set representative (root) for a given element
int findSet(DisjointSet *set, int element) {
    if (element != set->parent[element]) {
        // Path compression
        set->parent[element] = findSet(set, set->parent[element]);
    }
    return set->parent[element];
}

// Function to perform the union of two sets
void unionSets(DisjointSet *set, int element1, int element2) {
    int root1 = findSet(set, element1);
    int root2 = findSet(set, element2);

    if (root1 != root2) {
        // Union by rank
        if (set->rank[root1] < set->rank[root2]) {
            set->parent[root1] = root2;
        } else if (set->rank[root1] > set->rank[root2]) {
            set->parent[root2] = root1;
        } else {
            set->parent[root1] = root2;
            set->rank[root2]++;
        }
    }
}

// Function to destroy the disjoint set and free allocated memory
void destroySet(DisjointSet *set) {
    free(set->parent);
    free(set->rank);
    free(set);
}

int main() {
    int n = 10; // Number of elements in the set
    DisjointSet *set = createSet(n);

    // Perform union operations
    unionSets(set, 0, 1);
    unionSets(set, 2, 3);
    unionSets(set, 4, 5);
    unionSets(set, 6, 7);
    unionSets(set, 8, 9);

    // Check if elements belong to the same set
    printf("Are 0 and 1 in the same set? %s\n", findSet(set, 0) == findSet(set, 1) ? "Yes" : "No");
    printf("Are 2 and 4 in the same set? %s\n", findSet(set, 2) == findSet(set, 4) ? "Yes" : "No");
    printf("Are 3 and 7 in the same set? %s\n", findSet(set, 3) == findSet(set, 7) ? "Yes" : "No");

    // Cleanup
    destroySet(set);

    return 0;
}
