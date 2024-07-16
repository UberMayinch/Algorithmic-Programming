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
    string s;
    cin >> n;
    cin >> s;
      int countz=0;
    int counto=0;
    for(int i=0;i<n;i++){
      if(s[i]=='0' && (i == n-1 || (i < n-1 && s[i+1]=='1'))){
        countz++;
      }
      else if(s[i] == '1'){
        counto++; 
      }
    }
    if(countz >= counto){
      cout << "No" << endl;
    }
    else cout << "YES" << endl;

  }

}


