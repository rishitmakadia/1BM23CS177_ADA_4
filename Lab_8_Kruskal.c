#include <stdio.h>

void unionn(int i, int j, int parent[]) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

int find(int v, int parent[]) {
    while (parent[v] != v)
        v = parent[v];
    return v;
}

void kruskal(int n, int a[10][10]) {
    int count = 0, k = 0, sum = 0;
    int min, i, j, u, v, parent[10], temp[10][2];

    for (int l = 0; l < n; l++)
        parent[l] = l;

    while (count < n - 1) {
        min = 999;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] < min && a[i][j] != 0) {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        i = find(u, parent);
        j = find(v, parent);
        if (i != j) {
            unionn(i, j, parent);
            temp[k][0] = u;
            temp[k][1] = v;
            sum += a[u][v];
            count++;
            k++;
        }
        a[u][v] = a[v][u] = 999;
    }

    if (count == n - 1) {
        printf("Minimum Spanning Tree:\n");
        for (int m = 0; m < k; m++)
            printf("Edge (%d, %d)\n", temp[m][0], temp[m][1]);
        printf("Minimum Weight: %d\n", sum);
    } else {
        printf("Not a Spanning Tree\n");
    }
}

void main() {
    int n, i, j, a[10][10];
    printf("Enter No. of Vertices: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix (Cost)\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    kruskal(n, a);
}
