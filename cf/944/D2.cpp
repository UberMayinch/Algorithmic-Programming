#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
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
    cin >> s;
    int count = 1;
    for(int i=0;i<int(s.size())-1;i++){
      if(s[i] != s[i+1]){
        count++;
      }
    }
  if (s.find("01") != std::string::npos) {
        count -= 1;
    }
    cout << count << endl;
  }

}


