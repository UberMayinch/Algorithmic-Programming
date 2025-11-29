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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > 2* (b + 1) || b > 2* (a + 1) || c - a > 2 * (d - b + 1) || d - b > 2 * (c - a + 1)){
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
    
  }
}