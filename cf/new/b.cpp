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
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vi p(n);
    for(int i=0;i<n;i++){
        p[i]=abs(v[i]);
    }
    sort(p.begin(), p.end());
    ll f=v[0];
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        if(abs(f)==p[i]){
            break;
        }
        cnt++;
    }
    if(((n %2) && (cnt < n/2 )) || ((n % 2 == 0) && (cnt < n/2 -1))){
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
    
  }
}