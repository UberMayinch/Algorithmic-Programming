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
    int r=n-1;
    int l=0;
    for(int i=0;i<n/2;i++){
        if(v[i] == v[i+1] || v[n-1-i] == v[n-2-i]){
            v[i]=v[n-1-i];
        }
    }
    ll count=0;
    for(int i=0;i<n-1;i++){
        if(v[i] == v[i+1]){
            count++;
        }
    }
    cout << count << endl;
  }
}