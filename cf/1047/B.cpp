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
    vi ans(n);
    int z=3;
    int o=1;
    int t=2;
    for(int i=0;i<n;i++){
        if(v[i] % 3 == 1){
            ans[i] = t;
            t +=3;
        }
        else if(v[i] % 3 == 2){
            ans[i] = o;
            o +=3;
        }
        else{
            ans[i] = z;
            z +=3;
        }
    }
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    
  }
}