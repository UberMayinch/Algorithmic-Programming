#include <bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin >> t;
  while(t--){
    double n, k;
    cin >> n >> k;
    double ans=log2(k);
    if(n == 1){
      cout << k << endl;
      continue;
    }
    else{
      vector <long long int>v(n);
      long long int calc=pow(2, floor(ans))-1;
      v[0]=calc;
      long long int b = k-v[0];
      v[1]= b;
      for(int i=2;i<n;i++){
        v[i] = 0;
      }
      for(int i=0;i<n;i++){
        cout << v[i] << " ";
      }
      cout << endl;
    }
  }
}
