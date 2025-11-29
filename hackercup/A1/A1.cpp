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
  for(int j=0;j<t;j++)
  {
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    ll ans=0;
    if(n == 1){
        cout << "Case #" << j+1 << ": " << ans << endl;
    }
    else{
        for(int i=1;i<n;i++){
            ans = max(ans, abs(v[i]-v[i-1]));
        }
        cout << "Case #" << j+1 << ": " << ans << endl;
    }
  }
}