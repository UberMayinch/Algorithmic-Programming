#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& G, vector<bool>& vis, int start){
    vis[start-1]=true;
    for(auto neigh: G[start]){
        if(!vis[neigh-1]){
            dfs(G, vis, neigh);
        }
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Graph(n+1);
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    vector<bool>vis(n, false);
    vector<int> a;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            a.push_back(i+1);
            dfs(Graph, vis, i+1);
        }
    }
    cout << (a.size()-1)<< endl;
    for(int i=0;i<a.size()-1;i++){
        cout << a[i] << " " << a[i+1] << endl;
    }


}