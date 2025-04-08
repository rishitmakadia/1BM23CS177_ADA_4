#include <stdio.h>

#define INF 9999

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void dijkstra(int n, int cost[10][10], int src) {
    int dist[10], visited[10], parent[10];
    int i, j, u, min;

    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
        if (cost[src][i] != INF && i != src)
            parent[i] = src;
        else
            parent[i] = -1;
    }

    dist[src] = 0;
    visited[src] = 1;
    parent[src] = -1;

    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;

        // Find the nearest unvisited vertex
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[u][j] != INF && dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
                parent[j] = u;
            }
        }
    }

    // Output the shortest path and cost
    printf("\nShortest paths from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] != INF) {
            printf("Path to %d: %d", i, src);
            printPath(parent, i);
            printf(" | Cost: %d\n", dist[i]);
        } else {
            printf("No path to vertex %d\n", i);
        }
    }
}

void main() {
    int n, i, j, src;
    int cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(n, cost, src);
}

