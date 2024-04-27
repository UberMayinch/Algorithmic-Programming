#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
  int t;
  cin >> t;
  while(t--){
    long long int n, k;
    cin >> n >> k;
    long long int exp = 1;
    vector<long long int> v;
    long long int left = k;
    int iter=1;
    while((left >= 0)&&(iter < n)){
      left -= exp;
      if(left < 0){
        left += exp;
        break;
      }
      v.pb(exp);
      exp = exp * 2;
      iter+=1;
    }
    v.pb(left);
    while(iter < n){
      v.pb(0);
      iter++;
    }
    for(auto it: v){
      cout << it << " ";
    }
    cout << endl;
    
  }
}

