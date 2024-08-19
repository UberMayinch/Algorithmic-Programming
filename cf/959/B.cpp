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
    cin >>n ;
    string a,b;
    cin >> a;
    cin >> b;
    int flag=0;
    for(int i=0;i<n;i++){
      if(b[i] == '1' && a[i]=='0'){
        flag=1;
        break;
      }
      else if(a[i]=='1' ){
        break;
      }
    }
    if(flag)
    cout << "NO" << endl; 
    else cout <<"YES" << endl;
  }

}


