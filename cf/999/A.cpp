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
    int odd=0;
    int even=0;
    for(int i=0;i<n;i++){
        if(v[i]%2){
            odd++;
        }
        else even++;
    }

    if(even > 0){
        cout << odd+1 << endl;
    }
    else cout << odd-1 << endl;
    
  }
}