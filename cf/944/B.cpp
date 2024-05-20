#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;

int main(){
  ll t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int flag=0;
    int idx;
    for(int i=0;i<s.size()-1;i++){
      if(s[i] == s[i+1]){
        continue;
      }
      else{
        idx=i; 
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      cout << "NO" << endl;
    }
    else{
      char temp = s[idx];
      s[idx]=s[idx+1]; 
      s[idx+1]=temp;
      cout << "YES" << endl;
      cout << s << endl;
    }
  }


}

