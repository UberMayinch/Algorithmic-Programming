#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<long long int,long long int>
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
    vector <pii> v(n);
    vi sm(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first;
    }
    for(int i=0;i<n;i++){
        cin >> v[i].second;
        sm[i] = max(v[i].first, v[i].second);
    }

    ll sum = accumulate(sm.begin(), sm.end(), 0LL);
    vi ans(n, sum);
    for(int i=0;i<n;i++){
        ans[i] -=sm[i];
        ans[i] += v[i].first;
        ans[i] += v[i].second;
    }
    sum = *max_element(ans.begin(), ans.end());
    // int max_index = max_element(sm.begin(), sm.end()) - sm.begin();
    // for(int i = 0; i < n; i++) {
    //     if(i != max_index) {
    //         sum += max(v[i].first, v[i].second);
    //     }
    // }
    // sum += sm[max_index];
    cout << sum << endl;
    
  }
}