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
    int m, a, b,c;
    cin >> m >> a >> b >> c;
    ll sum=0;
    if(a > m){
        sum +=m;
    }
    else if(a + c >= m){
        sum +=m;
        c -= m-a;
    }
    else{
        sum += a + c;
        c = 0;
    }
    if(b > m){
        sum +=m;
    }
    else if(b + c >= m){
        sum += m;
        c -= b-a;
    }
    else{
        sum += b + c;
        c = 0;
    }
    cout << sum << endl;
    
  }
}