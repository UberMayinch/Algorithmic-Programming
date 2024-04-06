#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve(){

}

int main(){

  int t;
  cin >> t;
  while(t--){
    ll n, m, k;
    cin >> n >> m >> k;
    vector <long long int> v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    ll sum = 0;
    ll z = k / m;
    sort(v.begin(), v.end());
    for(int i=0;i<z;i++){
      sum+=m*v[i];
    }
    if(z < n){
      sum += (k % m)*v[z];
    }
    sum+=(k % m)*m*z + m*m*((z-1)*(z)/2);
    cout << sum;
    cout << endl;
  }
}
