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
    int n, k;
    cin >> n >> k;
    ll sum=0;
    vector <pair<ll,ll>> rects(n);
    set <pair<int,int>>;
    for(int i=0;i<n;i++){
      ll x, y;
      cin >> x >> y;
      sum+=x+y;
      rects[i]=mp(x,y);
      pair<
    }
    if(sum < k){
      cout << "-1" << endl;
    }
    else{
      
    }

  }

}


