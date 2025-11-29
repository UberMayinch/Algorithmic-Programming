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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int mx = 0;
    int curr=0;
    for(int i=0;i<n;i++){
      if(s[i] == '1'){
        curr++;
        mx = max(curr, mx);
      }
      else curr=0;
    }
    // cout << curr << endl;
    if(mx >= k){
      cout << "NO" << endl;
    }
    else{
      vi v(n);
      int idx=0;
      for(int i=0;i<n;i++){
        v[i]=i+1;
      }
      vi ans(n, -1);
      for(int i=0;i<n;i++){
        if(s[i] == '1'){
          ans[i]=v[idx++];
        }
      }
      for(int i=0;i<n;i++){
        if(ans[i] == -1){
          ans[i]=v[idx++];
        }
      }
      cout << "YES" << endl;
      for(auto it: ans){
        cout << it << " ";
      }
      cout << endl;
    }
    
  }
}