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
    int l1, l2,l3, b1,b2,b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if((l1 > b1) && (((l2 == l1) && (l3 == l1) && (b2 + b3 == l1-b1))||(b2 == l1 - b1) && (b3 == l1-b1) && (l2 + l3 == l1)))
        cout << "YES" << endl;
    else if((b1 > l1) && (((b2 == b1) && (b3 == b1) && (l2 + l3 == b1-l1))||(l2 == b1 - l1) && (l3 == b1-l1) && (b2 + b3 == b1)))
        cout << "YES" << endl;
    else cout << "NO" << endl;
    
  }
}