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
    ll n, a, b;
    cin >> n >> a >> b ;
    if(a >= b){
      cout << n * a << endl;
    }
    else{
      if(n > (b-a)){
        ll k = b-a;
        cout << (n-k)*a + k*b - k * (k-1)/2 << endl; 
      }
      else{
        cout << n*b - n*(n-1)/2 << endl;
      }
    }

  }

}


