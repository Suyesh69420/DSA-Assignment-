#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int sptSet[]){
    int min=INT_MAX, idx=-1;
    for(int v=0; v<V; ++v) if(!sptSet[v] && dist[v]<=min){ min=dist[v]; idx=v; }
    return idx;
}

void shortPath(int graph[V][V], int src){
    int dist[V]; int sptSet[V]={0};
    for(int i=0;i<V;++i) dist[i]=INT_MAX;
    dist[src]=0;
    for(int count=0; count<V-1; ++count){
        int u=minDistance(dist, sptSet);
        if(u==-1) break;
        sptSet[u]=1;
        for(int v=0; v<V; ++v){
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v] < dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }
    printf("Vertex\tDistance from Source %d\n", src);
    for(int i=0;i<V;++i) printf("%d\t%d\n", i, dist[i]==INT_MAX?-1:dist[i]);
}

int main(){
    int graph[V][V] = {
      {0,9,0,0,0},
      {9,0,10,5,0},
      {0,10,0,6,2},
      {0,5,6,0,3},
      {0,0,2,3,0}
    };
    shortPath(graph,0);
    return 0;
}
