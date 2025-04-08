#include <stdio.h>

int cost[10][10], vt[10], et[10][2], vis[10], n;
int sum = 0, x = 1, e = 0;

void prims() {
    int m, j, min, u, v, k;
    vt[x] = 1;
    vis[1] = 1;

    for (int s = 1; s < n; s++) {
        min = 999;  
        j = x;

        while (j > 0) {
            k = vt[j];
            for (m = 1; m <= n; m++) {  
                if (vis[m] == 0 && cost[k][m] != 0 && cost[k][m] < min) {
                    min = cost[k][m];
                    u = k;
                    v = m;
                }
            }
            j--;
        }

        vt[++x] = v;
        e++;
        vis[v] = 1;
        sum += min;
        et[e][0] = u;
        et[e][1] = v;
    }
}

void main() {
    printf("Enter No. of Vertices: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix (Cost):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = 999;  
            }
        }
        vis[i] = 0;  
    }

    prims();

    printf("Spanning Tree:\n");
    for (int i = 1; i <= e; i++) {
        printf("(%d, %d)\t", et[i][0], et[i][1]);
    }
    printf("\nMinimum Weight = %d\n", sum);
}
