#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve(int n, vi p){
  vi a(n);
  int mex=n;
  for(int i=n-1;i>=0;i--){
    a[i]=mex - p[i];
    if(a[i] < mex){
      mex = a[i];
    }
  }
  for(int i=0;i<n;i++){
    cout << a[i]<< " ";
  }
}

int main(){
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }

    solve(n, v);
  }
  cout << endl;
}
