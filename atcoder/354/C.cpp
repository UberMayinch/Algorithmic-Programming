#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
typedef vector<long long int> vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vi a(n);
  vi c(n);
  vector<pair<pair<int,int>, int>> ac(n);
  vi rem(n, 1);
  
  for(int i = 0; i < n; i++){
    cin >> a[i] >> c[i]; 
    ac[i] = make_pair(make_pair(c[i], a[i]), i);
  }
  
  sort(ac.begin(), ac.end()); 
  // for(auto it: ac){
  //   cout << it.first.first << " " << it.first.second << " " << it.second << " " << endl;
  // }
  for(auto it = ac.begin(); it != ac.end(); ){
    int cur = it->first.first;
    int val = it->first.second;
    int index = it->second;
    
    auto jt = it;
    ++jt;
    while(jt != ac.end() && jt->first.second < val){
        rem[jt->second] = 0;
      ++jt;
    }
    
    it = jt;
  }
  
  int counter = 0;
  for(int i = 0; i < n; i++){
    if(rem[i] == 1){
      counter++;
    }
  }
  
  cout << counter << endl;
  for(int i = 0; i < n; i++){
    if(rem[i] == 1){
      cout << i+1 << " ";
    }
  }
  cout << endl;
  
  return 0;
}
