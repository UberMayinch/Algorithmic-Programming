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
    int n, a ,b;
    cin >> n >> a >> b;
    if((b > a && b % 2 == n % 2) || (a % 2 == b % 2 && a % 2 == n % 2)){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    
  }
}