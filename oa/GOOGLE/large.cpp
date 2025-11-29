#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int binexp(int base, int pow){
    if(pow == 1){
        return (base % MOD);
    }
    else if(pow == 0){
        return 1;
    }
    else{
        if(pow % 2){
            return (base % MOD) * (binexp(base, pow-1) % MOD) % MOD;
        }
        else{
            int ans = (binexp(base, pow-1) % MOD);
            return (ans * ans) % MOD;
        }
    }
    return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());
  vector<int> final;
  for(int i=0;i<k;i++){
    final.push_back(v[i]);
  }
  cout << binexp(final[k-1]);
  for(int )
  
}