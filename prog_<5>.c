/* prog_5.c - Commit 2 (partial) */
#include <stdio.h>
#include <string.h>

#define V 5

void runBFS(int adj[V][V], int start) {
    int visited[V]; memset(visited,0,sizeof(visited));
    int q[V], head=0, tail=0;
    visited[start]=1; q[tail++]=start;
    while(head<tail){
        int u=q[head++];
        printf("%d ",u);
        for(int v=0; v<V; ++v) if(adj[u][v] && !visited[v]){ visited[v]=1; q[tail++]=v; }
    }
}

void dfsRec(int adj[V][V], int u, int visited[]){
    visited[u]=1; printf("%d ", u);
    for(int v=0; v<V; ++v) if(adj[u][v] && !visited[v]) dfsRec(adj,v,visited);
}
void runDFS(int adj[V][V], int start){ int visited[V]; memset(visited,0,sizeof(visited)); dfsRec(adj,start,visited); }

int main() {
    int adj[V][V] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    printf("BFS: "); runBFS(adj,0); printf("\nDFS: "); runDFS(adj,0); printf("\n");
    return 0;
}
