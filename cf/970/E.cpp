#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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
    int n;
    cin >>n ;
    vi v(n);
    ll sum=0;
    ll sq = 0;
    for(int i=0;i<n;i++){
      cin >> v[i]; 
      sum +=v[i] % MOD;
      sq += (v[i]*v[i]) % MOD;
    }
    ll p = ((sum % MOD)*(sum % MOD) - sq) % MOD;
    ll q = 2*n;
    //find modular inverse of q;
    cout << q * p % MOD << endl;

    
  }

}


