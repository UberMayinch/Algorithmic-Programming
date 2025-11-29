
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >>n ;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    ll max_o=0;
    ll max_e=0;
    for(int i=0;i<n;i++){
        if(i %2 == 0){
            max_e = max(v[i], max_e);
        }
        else{
            max_o = max(v[i], max_o);
        }
    }
    max_o += n /2;
    max_e += n - n/2;
    cout << max(max_o, max_e) << endl;

  }

}




