#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve(int n, int k){
  if(k == n){
    for(int i=0;i<n;i++){
      cout << "1 ";
    }
  }
  else if(k == 1){
    for(int i=0;i<n;i++){
      cout << i+1 << " ";
    }
  }
  else{
    cout << "-1";
  }
  cout << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    solve(n, k);
  }
}

