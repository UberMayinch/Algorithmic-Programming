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
    int l, r;
    cin >> l >> r;
    int count=0;
    while(l <= r){
      if(l % 2){
        if(l+2 <= r){
          count+=1;
          l+=2;
        }
      }
      l++;
    }
    cout << count << endl;

  }

}


