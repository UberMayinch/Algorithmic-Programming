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
    int a, b;
    cin >> a >> b;
    int c, d;
    cin >> c >> d;
    if((a >= b) && (c <= d) || (b >= a) && (d <= c)){
      cout << "NO" << endl;
    }
    else cout << "YES" << endl;

  }

}


