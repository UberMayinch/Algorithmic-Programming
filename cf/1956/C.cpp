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
    ll n;
    cin >> n;
    ll toChange =(n+1) / 2;
    ll sum= n * n * (n+1)/2;
    for(int i=0;i<toChange;i++){
      sum+=n*((n+1) - 2*(i+1))/2;
    }
    ll toRevert=(toChange+1)/2;
    for(int i=0;i<toRevert;i++){
      sum+=toChange*(toChange+1)/2 - (i+1)*toChange;
    }
    ll m = n + toChange + toRevert;
    if(n == 1)m=1;
    cout << sum << " " << m << endl;
    for(int i=0;i<n;i++){
      cout << 2 << " "<< i+1 << " ";  
      for(int j=0;j <n;j++){
        cout << n-j << " ";
      }
      cout << endl;
    }
    if(n != 1){
    for(int i=0;i<toChange;i++){
      cout << 1 << " " << n-i << " ";
      for(int j = 0;j< n;j++){
        cout << n - j << " ";
      }
      cout << endl;
    }
    for(int i=0;i<toRevert;i++){
      cout << 2 << " " << n-i << " ";
      for(int j=0;j<n;j++){
        cout << n-j << " ";
      }
      cout << endl;
    }
    }
  }
}

