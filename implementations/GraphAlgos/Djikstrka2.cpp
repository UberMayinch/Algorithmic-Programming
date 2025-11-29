#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF (int)1e9+7


void DjikstraNaive(int src, vector<vector<pair<int,int>>>G, vector<int>& d, vector<int>& p){

    int n = G.size()-1;
    d.assign(n, INF);
    p.assign(n, -1);

    vector<bool>m(n, false);
    d[src]=0;

    for(int i=0;i<n;i++){
        int v = -1;
        for(int j=0;j<n;j++){
            if(!m[j] && (v == -1 || d[v] < d[j])){
                v = j;
            }
        }

        if(d[v] == INF){
            break;
        }

        m[v]=true;

        for(auto it: G[v+1]){
            int len = it.first;
            int to = it.second;

            if(d[v] + len < d[to]){
                d[to]=d[v]+len;
                p[to]=v;
            }
        }
    }

    return;
}

void DjikstraSet(int src, vector<vector<pair<int,int>>>G, vector<int>&d, vector<int>&p){

    int n = G.size()-1;
    
    //0-indexed
    d.assign(n, INF);
    p.assign(n, -1);

    set<pair<int,int>>Q;
    Q.insert({0, src});

    while(!Q.empty()){
        int len = Q.begin()->first;
        int to = Q.begin()->second;
        Q.erase(Q.begin());

        //G is 1 indexed

        for(auto it:G[to]){
            if(d[it.second-1] > d[to-1] + it.first){
                Q.erase({d[it.second-1], it.second});
                d[it.second-1] = d[to-1] + it.first;
                p[it.second-1]=to-1;
                Q.insert({d[it.second-1], it.second});
            }
        }

    }

    return;
    
}

void restore_path(int s, int t, vector<int>&p){
    vector<int>pf;
    for(int i=t-1;i!=s-1;i=p[i]){
        pf.pb(i);
    }
    pf.pb(s);
    reverse(pf.begin(), pf.end());

    for(auto it: pf){
        cout << it+1 << " ";
    }
    return;
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> G(n+1);
    for(int i=0;i<m;i++){
        int x, y ,z;
        cin >> x >> y >> z;
        G[x].pb(make_pair(y, z));
        G[y].pb(make_pair(x, z));
    }
    
    vector<int>d (n, INF);
    vector<int>p (n, -1);

    DjikstraSet(1, G, d, p);

    if(p[n-1] != -1){
        restore_path(1, n, p);
    }
    else cout << "-1" << endl;

}