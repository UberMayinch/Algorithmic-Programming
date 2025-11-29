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
    if(a == 0){
        cout << "1" << endl;
    }
    else{
        int ans=a;
        int ex=0;
        if(b >= c){
            ans += 2 * min(b, c);
            b -=c;
            if(b != 0 || d != 0){
                ex = 1;
            }
            ans += min(a + ex, b+d);
        }
        else if(c > b){
            ans += 2 * min(b, c);
            c -= b;
            if(c != 0 || d != 0){
                ex = 1;
            }
            ans += min(a + ex, c+d);
        }
        cout << ans << endl;
    }
    
  }
}