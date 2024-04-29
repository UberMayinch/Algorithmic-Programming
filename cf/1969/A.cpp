#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, u;
    cin >> n;
    vector <int> v(n);
    vector <int> p(n);
    for(int i=0;i<n;i++){
      v[i]=i;
      cin >>u;
      p[i]=u-1;
      // cout << p[i] << " " << endl;
    }
    int count=3;
    for(int i=0;i<n;i++){
        if(p[p[i]] == i){
        count = 2;
        }
      }
      cout << count << endl;
  }
}
