#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve(){

}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    int count=0;
    int flag = 0;
    int i=0;
    int j=n-1;
    if(v[i] != v[j]){
      cout << "0";
      flag = 2;
    }
    if(flag != 2){
      for(int i=0;i<n;i++){
        if(v[i] != v[i+1]){
          break;
        }
      }
      for(int j=0;j<n;j++){
        if (v[n-1-j] != v[n-2-j]){
          break;
        }
      }
      cout << min(i, j)+1;
    }
    
    cout << endl;
  }
}

