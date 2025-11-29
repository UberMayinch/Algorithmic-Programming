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
    vi c(n);
    for(int i=0;i<n;i++){
        int count=0;
        // int jmx=i;
        for(int j=i+1;j<n;j++){
            if(v[j] > v[i]){
                count++;
            }
        }
        c[i] = count+i;
    }
    // for(auto it: c){
    //     cout << it << " ";
    // }
    // cout << endl;
    ll mn = 2001;
    for(int i=0;i<n;i++){
        mn = min(c[i], mn);
    }
    cout << mn << endl;
    
  }
}