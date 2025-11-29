#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  vector<vector<int>>grid(n, vector<int>(n, INT_MAX));
vector<vector<bool>> proc(n, vector<bool>(n, false));
  queue<pair<int,int>>q;
  q.push({0, 0});
  grid[0][0]=0;
  
  while(!q.empty()){
    auto curr = q.front();
    q.pop();
    for(auto [dx, dy]: dxy){
        int nx = curr.first + dx;
        int ny = curr.second + dy;
        // cout << nx << " " << ny << endl;

        if(nx < n && ny < n && nx >= 0 && ny >= 0 && proc[nx][ny] == false){
            q.push({nx, ny});
            grid[nx][ny] = min(grid[nx][ny], grid[curr.first][curr.second]+1);
            proc[nx][ny]=true;
        }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout << grid[i][j] << " ";
    }
    cout << endl;
  }


}