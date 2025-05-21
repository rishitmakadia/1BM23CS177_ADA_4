#include <stdio.h>
#include <stdlib.h>

#define INF 99999

// Union-Find functions
int find(int v, int parent[]) {
    while (parent[v] != v)
        v = parent[v];
    return v;
}

void unionn(int i, int j, int parent[]) {
    int pi = find(i, parent);
    int pj = find(j, parent);
    parent[pj] = pi;
}

void kruskal(int n, int a[][n]) {
    int parent[n], count = 0, sum = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    while (count < n - 1) {
        int min = INF, u = -1, v = -1;

        // Find the minimum edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] < min) {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u == -1 || v == -1)
            break; // No more valid edges

        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu != pv) {
            unionn(pu, pv, parent);
            printf("Edge (%d, %d) = %d\n", u, v, min);
            sum += min;
            count++;
        }

        // Mark edge as used
        a[u][v] = a[v][u] = INF;
    }

    if (count == n - 1)
        printf("Minimum Sum = %d\n", sum);
    else
        printf("Graph is not connected\n");
}

int main() {
    int points[][2] = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    int n = sizeof(points) / sizeof(points[0]);

    int adj[n][n];

    // Create Manhattan distance adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j)
                adj[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            else
                adj[i][j] = INF;  // No self-loop
        }
    }

    kruskal(n, adj);
}
