#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve(int n){
  for(int j=0;j<2*n;j++){
    for(int i = 0;i<2*n;i++){
      if((i + j) % 2 == 0){
        cout << "#";
      } 
      else{
        cout << "..";
      }
    } 
    cout << endl;
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    solve(n);
  }
}

