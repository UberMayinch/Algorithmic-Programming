#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
  int n;
  int sum;
  cin >> n >> sum;
  vector<long long int>v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  vector<long long int>pre(n+1);
  pre[0]=0;
  pre[1]=v[0];
  for(int i=2;i<n+1;i++){
    pre[i]=pre[i-1]+v[i-1];
  }
  int idx_a=0;
  int idx_b=0;
  int count = 0;
  cout << endl;
  while(idx_b < n+1){
    if(pre[idx_b] - pre[idx_a] == sum){
      count +=1;
      idx_a++;
    }
    else if(pre[idx_b] - pre[idx_a] > sum){
      idx_a ++;
    }
    else if(pre[idx_b]-pre[idx_a] < sum){
      idx_b++;
    }
  }
  cout << count;
}
