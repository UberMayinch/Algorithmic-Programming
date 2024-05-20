#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    long long int n, m;
    cin >> n >> m;
    long long int sum=0;
    for(int i=1;i<=m;i++){
      if((i-1)*i > n){
        break;
      } 
      else{
        sum+=(n/(i*i));
        if(n % (i*i) >= (i-1)*i){
          sum +=1;
        }
      }
    }
    cout << sum -1 << endl;
  }
}
