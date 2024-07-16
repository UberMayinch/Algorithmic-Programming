#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    if(n == 1) cout << 0 << endl;
    else{
        int sum=0;
      while(n > 1){
        sum++;
        n=n-k+1;
      }
      cout << sum << endl;
    }
      
  }

  }



