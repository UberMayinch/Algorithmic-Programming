#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>dxy = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(){
  int m, n;
  cin >> m >> n;
  vector<vector<pair<char, pair<char, int>>>>grid(m, vector<pair<char,pair<char, int>>>(n));
  pair<int,int>start;
  pair<int,int>end;

  for(int i=0;i<m;i++){
    string s;
    cin >> s;
    for(int j=0;j<n;j++){
      grid[i][j].first = s[j];
      grid[i][j].second.second = -1;
      if(s[j] == 'A'){
        start = {i, j};
        grid[i][j].second.second = 0;
      }
      if(s[j] == 'B'){
        end = {i, j};
      }
    }
  }

  queue<pair<int,int>>q;
  q.push(start);
  while(!q.empty()){
    if(q.front() == end)break;
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(auto [dx, dy]: dxy){
      int nx = x + dx;
      int ny = y + dy;
      
      if(nx < m && nx >= 0 && ny < n && ny >= 0 && (grid[nx][ny].first != '#') && (grid[nx][ny].second.second == -1)){
        q.push({nx, ny});
        grid[nx][ny].second.second = grid[x][y].second.second + 1;
        // cout << nx << " " << ny << endl;
        if(dx == 1 && dy == 0){
          grid[nx][ny].second.first = 'D';
        }
        else if(dx == -1 && dy == 0){
          grid[nx][ny].second.first = 'U';
        }
        else if(dx == 0 && dy == -1){
          grid[nx][ny].second.first = 'L';
        }
        else if(dx == 0 && dy == 1){
          grid[nx][ny].second.first = 'R';
        }
      }
    }
  }
  if(grid[end.first][end.second].second.second == -1){
    cout << "NO" << endl;
  }
  else{
    cout << "YES" << endl;
    cout << grid[end.first][end.second].second.second << endl;
    string ans;
    auto curr = end;
    while(curr != start){
      if(grid[curr.first][curr.second].second.first == 'L'){
        ans += "L";
        curr = {curr.first, curr.second + 1};
      }
      else if(grid[curr.first][curr.second].second.first == 'U'){
        ans += "U";
        curr = {curr.first + 1, curr.second};
      }
      else if(grid[curr.first][curr.second].second.first == 'D'){
        ans += "D";
        curr = {curr.first - 1, curr.second};
      }
      else if(grid[curr.first][curr.second].second.first == 'R'){
        ans += "R";
        curr = {curr.first, curr.second - 1};
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }

}