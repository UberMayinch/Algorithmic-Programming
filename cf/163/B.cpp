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
    int flag=1;
    int check =0;
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    for(int i=0;i<n;i++){
      if((v[i] > v[i+1]) && (i != n-1)){
      if(v[i] > 10){
      if(( v[i]/10 > v[i] % 10) || (check > (v[i] / 10))){
        cout << "NO" << endl;
        flag=0;
        break;
      }
      else{
        check = v[i] % 10;
      }
      }
      else{
        if(check > v[i]){
          cout << "NO" << endl;
          flag=0;
          break;
        }
        else check = v[i];
      }
    }
    }
  
    if(flag != 0) cout << "YES" << endl;
  }

}

