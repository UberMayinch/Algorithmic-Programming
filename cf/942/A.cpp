#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >>n;
    vector<int> v1(n);
    vector <int> v2(n);
    for(int i=0;i<n;i++){
      cin >> v1[i];
    }
    for(int i=0;i<n;i++){
      cin >> v2[i];
    }
    int count=0;
    int i=0;
    int j =0;
    while(i < n){
    if(j == n){
        break;
      }
    if(v1[i] > v2[j]){
          j++;
          count ++;
    }
      else {
        i++;
        j++;
      }
    }
    cout << count << endl;
  }
}
