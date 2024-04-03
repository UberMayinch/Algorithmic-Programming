#include <bits/stdc++.h>
using namespace std; 

long long int solve(long long int a,  long long int b, long long int c){
   long long ans = (c / a) + (c / b) + 2; 
   return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    long long int a, b,c;
    cin >> a >> b >> c;
    cout << solve(a,b,c);
    cout << endl;
  }
}
