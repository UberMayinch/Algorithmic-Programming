#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int t, k;
    cin >> t >> k;
    if(k >= t-1){
      cout << 1 << "\n";
    }
    else{
      cout << t << "\n";
    }
  }
}
