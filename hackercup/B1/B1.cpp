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
  for(int j=0;j<t;j++)
  {
    int n, a, b;
    cin >> n >> a >> b;
    cout << "Case #" << j+1 << ": ";
    for(int i=0;i<2*n-1;i++){
        cout << "1 ";
    }
    cout << b << endl;
    }
}