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
    cin >>n;
    string s;
    cin >> s;
    queue <char>free;
    for(int i=0;i<n-1;i++){
      if(s[i] ! = s[i+1]){
        free.pb(s[i]);
      }
      else if(s[i] == s[i+1] && s[i] == s[i+2]){
        // find the first character in free that is not equal to s[i]
        s[i+2]=free.find( !s[i]);
        free.pb(s[i+2]);
      }
    }
    //concatenate whatever is left in queue to the end of the string

    cout << s << endl;

  }

}


