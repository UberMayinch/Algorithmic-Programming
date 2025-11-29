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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int g = min(a, c);
    int f = min(b, d);
    if(g >= f) cout << "Gellyfish" << endl;
    else cout << "Flower" << endl;
    
  }
}