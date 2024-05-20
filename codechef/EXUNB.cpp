#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if((n % 2 == 1) && (n > 1)){
      cout << "YES" << endl;
      for(int i=0;i<n;i++){
        vector<int>v(((n-1)/2)*n, 0);
        for(int j=i+1;j<i+(n-1)/2;j++){
          if(j > n-1){
            j = j % n;
          }
          v[j] = 1;
      }
        for(auto it:v){
          cout << it;
        }
        cout << endl;
      }
    }
    else cout << "NO" << endl;
  }

}


