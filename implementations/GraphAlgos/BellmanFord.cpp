#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9

typedef struct edge{
    int a;
    int b;
    int weight;

}edge;

int naiveBF(edge* edges, int n, int m, int src, int dest){
    vector<int> dist(n+1, INF+1);
    dist[src]=0;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(dist[edges[j].a] < INF){
                dist[edges[j].b]=min(dist[edges[j].b], dist[edges[j].a]+edges[j].weight);
            }
        }
    }
   
    return dist[dest];
}

int ESBF(edge* edges, int n, int m, int src, int dest){
    vector<int> dist(n+1, INF+1);
    dist[src]=0;

    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<m;j++){
            if(dist[edges[j].a] < INF){
                if(dist[edges[j].a] + edges[j].weight < dist[edges[j].b]) flag=1;
                dist[edges[j].b] = min(dist[edges[j].b], dist[edges[j].a]+ edges[j].weight);
            }
        }
        if(!flag)break;
    }
    return dist[dest];
}

int main(){
    int n=5;
    int m=6;

    edge edges[m];
    edges[0]={1,2,3};
    edges[1]={2,3,4};
    edges[2]={3,4,5};
    edges[3]={1,4,10};
    edges[4]={4,5,2};
    edges[5]={3,5,4};

    int src=1;
    int dest=5;
    
    cout << naiveBF(edges, n, m, dest, src) << endl;
    cout << ESBF(edges, n, m, dest, src) << endl;

}