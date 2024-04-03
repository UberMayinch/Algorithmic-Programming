#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> pre(n+1);
  pre[0]=0;
  for(int i=1;i<n+1;i++){
    pre[i]=pre[i-1]+a[i-1]
  }

}
