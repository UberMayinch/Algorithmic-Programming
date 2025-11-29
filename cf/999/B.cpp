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
    sort(v.begin(), v.end());
    ll mx = -1;
    ll mn = (ll)1e9;
    ll mn_i=-1;

    for(int i=0;i<n-1;i++){
        if(i < n-1 && v[i] == v[i+1]){
            mx = v[i];
            i+=2;
        }
        if(i < n-1 && (v[i+1]-v[i] < mn)){
            mn = v[i+1]-v[i];
            cout << mn << endl;
            mn_i=i;
        }
    }
    // cout << mx << endl << mn << endl;
    if(mx != v[1] && mx != -1){
        cout << v[0] << " " << v[1] << " "<< mx << " "<< mx << " " << endl;
    }
    else if(mx == v[1] && (mn*mn) < 4*mx*mx){
        cout << v[mn_i] << " " << v[mn_i+1] << " "<< mx << " "<< mx << " " << endl;
    }
    else cout << -1 << endl;
    
  }
}