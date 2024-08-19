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
    int n,k;
    cin >> n >> k;
    int diag_val=n;
    int count=0;
    if(k > n){
      k -=n;
      count++;
    for(int i=0;i<n-1;i++){
      diag_val--;
      for(int j=0;j<2;j++){
        if(k >= diag_val){
          count++;
          k-=diag_val;
        }
      }
    }
      cout << count << endl;
    }
    else if(k == 0){
      cout << "0" << endl;
    }
    else cout << "1" << endl;

  }

}


