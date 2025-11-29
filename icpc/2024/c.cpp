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
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vi a(n);
    for(int i=0;i < n; i++) {
        if (i == 0) {
            a[i] = v[i];
        } else {
            a[i] = a[i-1] + v[i];
        }
    }

    vi ans(n);

    ll sum=0;

    for(int i=0;i<n;i++){
        ll to_leave = (i+1)/(2*k);


        
    }

    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
  }
}