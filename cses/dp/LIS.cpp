#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int lis(vector<ll>& v, int n){
  vector<vector<pair<int,int>>>dp(2, vector<pair<int,int>>(n+1, {0,0}));
  dp[0][0]={0,0};
  dp[1][0]={0,0};
  for(int i=1;i<n+1;i++){
    // taking the current element in the increasing sequence if it is greater than the previous, otherwise start a new sequence.
    if(dp[0][i-1].second < v[i-1]){
      dp[0][i]=mp(dp[0][i-1].first, v[i-1]);
    }
    else dp[0][i]=mp(1, v[i-1]);

    //do not take the current element, largest sequence that can be formed without it. 
    dp[1][i]

  }
  
}

int main(){
  int n;
  cin >> n;
  vi v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  cout << lis(v, n) << endl;

}


