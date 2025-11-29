#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    string s;
    int z=0;
    int e=0;
    int t=0;
      cin >> s;
    for(int i=0;i<s.size();i++){
      if(atoi(s[i]) == 0){
        z = 1;
      }
      if(atoi(s[i]) % 2 == 0){
        e = 1;
      }
      t += atoi(s[i]);
    }
    if(t % 3 == 0){
      t = 1;
    }
    if(t && e && z){
      cout << "red" << endl;
    }
    else cout << "cyan" << endl;

  }

}


