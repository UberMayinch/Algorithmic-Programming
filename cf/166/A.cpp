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
    int flag=0;
    for(int i=0;i<n-1;i++){
      if(int(s[i+1]) < int(s[i])){
        if((s[i]-'a' < 0) && (s[i+1]-'a'>0)){
continue;
        }
        else{
        flag =1;
        break;
        }
      }
    }
    if(flag == 1){
      cout << "NO" << endl;
    }
    else cout << "YES" << endl;
  }

}


