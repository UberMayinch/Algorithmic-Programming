#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>G(n+1);
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<bool>vis(n, false);
    queue<pair<int,int>>Q;
    vector<int>par(n);
    par[0]=-1;
    vis[0]=true;

    Q.push({1, 0});
    int dist = -1;

    while(!Q.empty()){
        auto p = Q.front();
        Q.pop();
        if(p.first == n){
            dist = p.second;
            break;
        }
        else{
            for(auto it:G[p.first]){
                if(!vis[it-1]){
                    Q.push({it, p.second+1});
                    par[it-1]=p.first-1;
                    vis[it-1]=true;
                }
            }

        }
    }

    if(dist == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << dist + 1<< endl;
        vector<int> route;
        int curr = n-1;
        while(par[curr] != -1){
            route.push_back(curr+1);
            curr = par[curr];
        }
        route.push_back(1);
        for(auto it = route.rbegin();it != route.rend();it++){
            cout << *it << " ";
        }
        


    }


}