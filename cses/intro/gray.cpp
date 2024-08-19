#include <bits/stdc++.h>
using namespace std;

vector<string> solve( int n){
  if(n == 1){
    return{"1", "0"}; 
  }  
  else{
    vector<string> ans={};
    vector<string> lst=solve(n-1);
    for(auto bv: lst){
      ans.push_back("1"+bv);
    }
    for(auto it=lst.rbegin(); it != lst.rend();++it){
      ans.push_back("0"+ *it);
    }
    return ans;
  }
}

int main(){
  int n;
  cin >> n;
  vector<string> a=solve(n);
  for(auto w: a){
    cout << w << endl;
  }
}
