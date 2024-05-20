#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
typedef vector<long long int>vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    ll n, m;
    cin >> n >> m;
    string s[n];
    for(int i=0;i<n;i++){
      cin >> s[i];
    }
    deque<pair<int, int>> q;
    int grid[n][m];
    vector <vector<int>> dist(n, vector<int> (m, INT_MAX));

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        grid[i][j]=s[i][j]-'0';
        if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    dist[i][j]=grid[i][j]-'0';
                    if(grid[i][j]=='0')
                        q.push_front({i,j});
                    else
                        q.push_back({i,j});
                }
      }
    }
    
    while(!q.empty()){
      auto cur = q.front();
      int x = cur.first;
      int y = cur.second;
      q.pop_front();
      for(auto [dx, dy]: dxy){
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int nd = dist[x][y] + (s[nx][ny] == '1');
            if (dist[nx][ny] <= nd) continue;
            dist[nx][ny] = nd;
            q.push_back({nx, ny});
      }
    }

       int ans = 0;
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                if (s[i][j] == '0') ans = max(ans, dist[i][j]);
                        }
                }
    cout << ans << endl;
  }

}

