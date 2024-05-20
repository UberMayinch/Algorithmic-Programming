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
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int idx=0;
    int i=0;
    int count=0;
    while((idx < m)&&(i < n)){
      if(s1[i] == s2[idx]){
          count++;
          idx++;
          i++;
      }
      else{
        idx++;
      }
    }
    cout << count << endl;
    }
 }


