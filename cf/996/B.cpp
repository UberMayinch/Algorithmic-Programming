#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    vi v(n);
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vi dif(n);
    for(int i=0;i<n;i++){
        dif[i]=v[i]-a[i];
    }
    sort(dif.begin(), dif.end());
    if(-(dif[0]) <= dif[1]){
        cout <<"YES" << endl;
    }
    else cout << "NO" << endl;
    
  }
}