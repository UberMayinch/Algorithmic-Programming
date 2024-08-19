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
    vi v(n, 0);
    vi p(n);
    for(int i=0;i<n;i++){
      cin >> p[i];
    }
    int flag=0;
    for(int i=0;i<n;i++){
      v[p[i]-1]=1;
      flag=0;
      if(i > 0){
        if((p[i] > 1) && (v[p[i]-2] != 1)){
          flag+=1;
          if(p[i] == n){
            flag=2;
          }
        }
        if(v[p[i]] != 1 && (p[i]< n)){
          flag++;
          if(p[i] == 1){
            flag=2;
          }
          }
      }
      if(flag == 2){
        break;
      }
    }
    if(flag == 2){
      cout << "NO" << endl;
    }
    else cout << "YES" << endl;

  }

}


