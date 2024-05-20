#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;

set<string> solve(string s){
  set <string> mySet;
  if(s.size() == 1){
    mySet.insert(s);
  } 
  else{
    for(int i=0;i<s.size();i++){
      char currLet = s[i];
      string rem = s.substr(0, i) + s.substr(i + 1);
      set<string>rec = solve(rem);
      for(auto it: rec){
        mySet.insert(currLet + it);
      }
    }
  }
  return mySet;
}

int main(){
  string s;
  cin >> s;
  set <string> ans;
  ans = solve(s);
  cout << ans.size() << endl;
  for(auto it: ans){
    cout << it << endl;
  }
}

