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
    for(int i=0;i<n-2;i++){
        if(k % 2){
            v[i]=n;
        }
        else{
            v[i]=n-1;
        }
    }
    v[n-2]=n;
    v[n-1]=n-1;
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
}