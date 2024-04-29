#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    vector <long long int> v(n);
    vector <long long int> check(n,0);
    long long int sum=0;
    for(int i=0;i<n;i++){
      cin >> v[i];
      sum +=v[i];
    }
    if(n > 1){
    for(int i=0;i<n;i++){
      for(int j=max(0,i-k);j<min(n, i+k+1);j++){
          // cout << i << " " << j << endl;
          if(i != j){
            check.push_back(v[i]-v[j]);
          }
        }
      }
    }
    sort(check.begin(), check.end());
    for(auto it: check){
      cout << it << " ";
    }
    for(int i=0;i<k;i++){
      if(check[i] < 0){
      sum += check[i];
      }
    }
    cout << sum << endl;
  }
}
