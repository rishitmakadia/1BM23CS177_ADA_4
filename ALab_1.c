#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX], result[MAX], top=-1;

void dfs_top(int n, int adj[][MAX]){
    for(int i=0; i<n; i++)
        visited[i]=0;
    for (int j=0; j<n; j++){
        if(visited[j]==0)
            dfs(j,n,adj);
    }    
}

void dfs(int start, int n, int adj[][MAX]){
    visited[start]=1;
    for(int i=0; i<n; i++){
        if(adj[start][i]==1 && visited[i]==0)
            dfs(i,n,adj);
    }
    result[++top]=start;
}

int main(){
    int n;
    printf("Enter No. of Nodes: ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix: \n");
    for(int i=0; i<n;i++){
        for (int j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
        }
    }
    dfs_top(n, adj);
    printf("Topological Order: ");
    for(int k=(n-1) ; k>=0; k--){
        printf("\t%d", result[k]);
    }
}