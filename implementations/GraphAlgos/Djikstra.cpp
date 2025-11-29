#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define mp make_pair
#define pb push_back

void DjikstraNaive(int s, vector<vector<pair<int,int>>> G, vector<int>& p, vector<int>& d){
    int n=G.size()-1;
    vector<bool> m(n, false);
    vector<int> dist(n, INF);

    d[s]=0;

    for(int i=0;i<n;i++){
        int v = -1;
        
        // find the least distant unmarked vertex
        for(int j=0;j<n;j++){
            if(v == -1 || !m[j] && d[j] < d[v]){
                v=j;
            }
        }

        if(d[v] == INF){
            break;
        }

        m[v]=true;
        for(auto it: G[v+1]){

            //index first, distance second in pair
            if(d[it.second] > d[v] + it.first){
                d[it.second]= d[v] + it.first;
                
                //v is 0 indexed so we can restore path directly
                p[it.second]=v;
            }
        }
    }
    return;
}

vector<int> restore_path(vector<int>& p, int s, int t){

    vector<int> path;
    
    for(int i=t;i!=s;i=p[i]){
        path.pb(i);
    }
    path.pb(s);
    reverse(path.begin(), path.end());
    return path;
}

int DjikstraSet(){

}

int DjikstraHeap(){

}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>>G(n+1, vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        G[x].pb(mp(y, z));
        G[y].pb(mp(x, z));
    }

    vector<int>p(n, -1);
    vector<int>d(n, 0);

    DjikstraNaive(src, G, p, d);

    vector<int> ans = restore_path(p, 0, 2);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}