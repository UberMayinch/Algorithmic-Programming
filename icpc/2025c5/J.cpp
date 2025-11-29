#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int BFS(vector<vector<int>> G, int start, vector<bool> col){
    vector<bool> vis(G.size());
    queue<int>q;
    int count=0;
    q.push(start);

    vis[start]=true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neigh: G[curr]){
            if(neigh != curr && !vis[neigh] && col[neigh]){
                q.push(neigh);
                vis[neigh]=true;
            }
            count++;
        }
    }
    return count;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> col(k+1,false);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        col[x]=true;
    }
    int count=0;
    vector<vector<int>>G(k+1);
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    set<pair<int,int>>s;
    for(int i=0;i<k;i++){
        s.insert({(int)G[k].size(),i+1});
        
    }

    

    int friends=0;
    for(auto it = s.rbegin();it != s.rend();it++){
        cout << "hi " << it->second << endl;
        if(col[it->second] == false){
            friends++;
            col[it->second] = true;
        }
        if(friends == 2)break;
    }

    for(int i=0;i<k;i++){
        if(col[i+1] == true){
            count = BFS(G, i+1);
            break;
        }
    }

    cout << count << endl;
    
  }
}