#include <bits/stdc++.h>
using namespace std;

int solve(int * arr, int len){
  if(start > ) 
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int len;
    cin >> len;
    string x;
    cin >> x;
    int arr[n];
    arr[0]=int(x[0]);
    for(int i=1;i<n;i++){
      if(x[i] == 1){
        arr[i]=arr[i-1]+1;
      }
      else arr[i]=arr[i-1];
    }
    cout << solve(arr, len);
  }
}
