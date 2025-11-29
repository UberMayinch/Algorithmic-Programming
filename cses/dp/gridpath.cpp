#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  int n;
  cin >> n;
  string s[n];
  for(int i=0;i<n;i++){
    cin >> s[i]; 
  }
  vector<vector<long long int>>grid(n, vector<long long int>(n, 0));
  grid[0][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(s[i][j] == '*'){
        grid[i][j]=0;
      }
      else{
        if(i != 0){
          grid[i][j] = (grid[i][j] + grid[i-1][j]) % MOD;
        }
        if(j != 0){
          grid[i][j] = (grid[i][j] + grid[i][j-1]) % MOD;
        }
      }
      // cout << grid[i][j] << " ";
    }
    // cout << endl;
  }
  cout << grid[n-1][n-1] << endl;

}


