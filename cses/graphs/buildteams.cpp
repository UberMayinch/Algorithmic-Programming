#include <bits/stdc++.h>
using namespace std;

int main(){
    int flag=0;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> cols(n,-1);
    for(int i=0;i<n;i++){
        if(flag == 1){
            break;
        }
        if(cols[i] == -1){
            cols[i] == 1;
        }
        queue<pair<int,int>>q;
        q.push(make_pair(i+1, cols[i]));
        int colour = (cols[i] == 1)?2:1;
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            for(auto it: G[node.first]){
                if(cols[it-1] == -1){
                    q.push(make_pair(it, colour));
                    cols[it-1]=colour;
                }
                else if(cols[it-1] != colour){
                    flag=1;
                    break;
                }
            }
        }

    }
    if(flag){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(auto it: cols){
            cout << it << " ";
        }
    }
}