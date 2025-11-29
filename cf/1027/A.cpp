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
  map<int,int>m;
  for(int i=0;i<100;i++){
    m[i*i] = i;
  }
  while(t--) {
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << " " << 0 << endl;
    }
    else if(m[n] != 0){
        cout << 0 << " " << m[n] << endl;
    }
    else cout << -1 << endl;

    
  }
}