#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;

int main(){
  ll t;
  cin >> t;
  while(t--){
    int x, y;
    cin >> x >> y;
    cout << min(x, y) << " " << max(x, y);
    cout << endl;
  }

}

