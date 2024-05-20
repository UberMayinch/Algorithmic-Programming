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
    int count=1;
    int one=0;
    int flag=0;
    for(int i=0;i<s.size()-1;i++){
      if((s[0] == '1') && (one == 1) && (s[i] == '1')){
        flag = 1;
      }
      if(s[i] == '1'){
        one = 1;
      }
      if((one == 1)&&(s[i] != s[i+1])){
        count+=1;
      }
    }
    if((s[0] == '1') && (one == 1) && (s[s.size()-1] == '1')){
      count--;
    }
    if(flag == 1)count--;
    cout << count << endl;
  }
}
