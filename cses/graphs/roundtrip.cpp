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
    vector<int>vis(n, -1);
    unordered_map<int,int>par;
    int ans;
    for(int i=0;i<n;i++){
        if(vis[i] == -1){
            par[i+1] = -1;
            queue<pair<int,int>>q;
            q.push({i+1, 0});
            vis[i]=0;
            while(!q.empty()){
                auto p = q.front();
                q.pop();
                if(vis[p.first-1] != -1 && vis[p.first-1] != p.second){
                    ans = p.first;
                    break;
                }
                for(auto neigh: G[p.first]){
                    if(vis[neigh-1] == -1 || p.second - vis[neigh-1] > 2){
                        q.push({neigh, p.second+1});
                        if(vis[neigh-1] == -1){
                            vis[neigh-1] = p.second+1;
                        }
                        par[neigh] = p.first;
                    }
                }

            }
        }
    }
    vector<int> final;
    final.push_back(ans);
    while(par[ans] != final[0]){
        final.push_back(par[ans]);
        ans = par[ans];
    }
    final.push_back(ans);
    for(auto it = final.rbegin();it != final.rend();it++){
        cout << *it << " ";
    }

}