#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF (int)1e9

void DjikstraNaive(int src, vector<vector<pair<int,int>>>G, vector<int>& d, vector<int>& p){
    int n = G.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> m(n, false);

    for(int i=0;i<n;i++){
        int v = -1;
        for(int j=0;j<n;j++){
            if(!m[j] && (v == -1 || d[j] < d[v])){
                v = j;
            }
        }
        if(d[v] == INF)break;
        m[v] = true;
        for(auto it: G[v]){
            int len = it.first;
            int to = it.second;

            if(d[to] < d[v] + len){
                d[to]=d[v] + len;
                p[to]=v;
            }
        }
    }
    return;
}

void DjikstraSet(int src, vector<vector<pair<int,int>>> G, vector<int>& d, vector<int>& p){

    int n=G.size();
    d.assign(n, INF);
    p.assign(n, -1);

    set<pair<int,int>>q;
    q.insert({0, src-1});

    while(!q.empty()){
        int len = q.begin()->first;
        int to = q.begin()->second;

        for(auto it: G[to]){
            if(d[it.second] > d[to]+it.first){
                q.erase({d[it.second], it.second-1});
                d[it.second] = d[to]+it.first;
                p[it.second] = to;
                q.insert({d[it.second], it.second-1});
            }
        }
    }

    return;
}

void restore_path(int s, int t, vector<int>& p){
    vector<int> pf;
    for(int i=t-1;i!= s;i=p[i]){
        pf.pb(i);
    }
    pf.pb(s);
    reverse(pf.begin(), pf.end());
    for(auto it: pf){
        cout << it + 1 << " ";
    }
    return;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<pair<int,int>>>G(n);

    for(int i=0;i<m;i++){
        int x,y, z;
        cin >> x >> y >> z;
        G[y-1].pb(mp(x, z));
        G[x-1].pb(mp(y, z));
    }

    vector<int>d(n);
    vector<int>p(n);
    DjikstraSet(1, G, d, p);
    restore_path(1, n, p);
}