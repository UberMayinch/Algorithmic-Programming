#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define mp make_pair 
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
    vector <pair<int,int>> p(n);
    for(int i=0;i<n;i++){
      int x;
      cin >> x;
      pair<int, int> ele = mp(x, i);
      p[i] = ele; 
    }
    vi q(n, 0);
    set <pair<int,int>> max;
    set <pair<int,int>> min;
   for(int i=0;i<n;i++){
     if(i % 2 == 1){
        max.insert(p[i]); 
      } 
    else min.insert(p[i]);
    }
   if (!min.empty() && (--min.end())->first == n) {
       std::swap(max, min);
    }
    int lo = n;
    int idx;
    for(auto it: max){
      // cout << it.first << " " << it.second << endl;
      idx = it.second ;
      q[idx] = lo; 
      lo--;
    }
    for(auto it: min){
      idx = it.second;
      q[idx] = lo;
      lo --;
    }
    for(auto it: q){
      cout << it << " ";
    }
    cout << endl;
  }

}


