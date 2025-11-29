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
    bool flag=false;
    int idx;
    for(int i=0;i<n-1;i++){
        if(v[i+1] < v[i]){
            flag = true;
            idx=i;
        }
    }
    if(flag){
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << v[idx] << " " << v[idx+1] << endl;
    }
    else cout << "NO" << endl;
    
  }
}