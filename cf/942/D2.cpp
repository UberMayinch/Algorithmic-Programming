#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    long long int n, m;
    cin >> n >> m;
    long long int k=min(n, m);
    long long int sum=0;
    sum+= k /2;
    for(int i=2;i<n;i++){
      if(i % 2 == 1){

      if(i*(i-1)>m){
        break;
      }
      else sum+=2;
      }
    }
    cout << sum << endl;

  }
}
