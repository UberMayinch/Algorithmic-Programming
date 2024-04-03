#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int t;
    cin >> t;
    int idx=0;
    while(pow(2, ++idx)<t);
    idx=max(0,idx-1);
    cout << pow(2,idx) << "\n";
  }
}
