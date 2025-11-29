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
  vi sq;
  for(int i=0;i<10000;i++){
    sq.pb(i*i);
  }
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
     if (find(sq.begin(), sq.end(), n) == sq.end()) {
            cout << "No" << endl;
    }
    else{
      int flag=0;
      int rows = (int)sqrt(n);
      for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
          if(i == 0 || i == rows-1 || j == 0 || j == rows-1){
          if(s[i*rows+j] == '0'){
              flag=1;
          }
          }
          else{
            if(s[i*rows+j] == '1'){
              flag = 1;
            }
          }
        }
      }
      if(flag){
        cout << "No" << endl;
      }
      else cout << "Yes" << endl;
    }

  }

}


