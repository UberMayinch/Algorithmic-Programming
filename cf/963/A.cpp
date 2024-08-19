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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int countA=0;
    int countB=0;
    int countC=0;
    int countD=0;
    
    int ans=0;

    for(int i=0;i<4*n;i++){
      if(s[i] == 'A'){
        countA++;
      }
      if(s[i] == 'B'){
        countB++;
      }
      if(s[i] == 'C'){
        countC++;
      }
      if(s[i] == 'D'){
        countD++;
      }
      if
        (s[i] == '?')
      {
        continue;
      }
    }
    ans+=min(n, countA);
    ans+=min(n, countB);
    ans+=min(n, countC);
    ans+=min(n, countD);
    cout << ans << endl;
    
  }

}


