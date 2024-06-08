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
    int n, f, k;
    cin >> n >> f >> k;
    vi v(n);
    int fav;
    for(int i=0;i<n;i++){
      cin >> v[i];
      if(i == f-1){
        fav = v[i];
      }
    }
    sort(v.rbegin(), v.rend());
    
      if(v[k-1] > fav){
        cout << "NO" << endl;
      }
      if(v[k-1] < fav){
        cout << "YES" << endl;
      }
      if(v[k-1] == fav){
        if(k == n || v[k] != v[k-1]){
          cout << "YES" << endl;
        }
        else cout << "Maybe" << endl;
      }
    }
    
  }




