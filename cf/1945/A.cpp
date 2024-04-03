#include <bits/stdc++.h>
using namespace std;
long long int solve(long long int a,long long int b,long long int c){
    if((b+c) % 3 != 0 && b % 3 != 0 && c < 2){
      return -1; 
    }
    else{
      long long int k = (b+c) / 3;
      if((b+c) % 3 == 0){
        return a+k;
      }
      else{
        return a+k+1;
      }
    }
}
int main(){
  int t;
  cin >> t;
  while(t--){
    long long int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b,c);
    cout << endl;
  }
}
