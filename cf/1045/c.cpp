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
    ll sum = 0;
    ll diff;
    for(int i=1;i<n;i+=2){
        diff = 0;
        if(i + 1 < n){
            diff = max(v[i-1] + v[i+1]-v[i], 0LL);
        }
        else diff = max(v[i-1]-v[i], 0LL);
        if(v[i] > v[i-1]){
            v[i+1] = v[i+1] - diff;
        }
        else v[i+1] = 0;
        sum += diff;
    }
    cout << sum << endl;
  }
}