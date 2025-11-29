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
    cin >>n;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    vi a(n);
    a = v;
    sort(a.begin(), a.end());
    ll inv =0;
    for(int i=0;i<n;i++){
      ll idx = find(a.begin(), a.end(), v[i]) - a.begin();
      if(idx > i){
      inv += idx -i;
      }
      
    }
    cout << inv << endl;
    (inv % 2)? cout << "NO": cout << "YES"; cout << endl;

  }

}


