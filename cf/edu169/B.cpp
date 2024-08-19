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
    int la,ra;
    int lb,rb;
    cin >> la >> ra;
    cin >> lb >> rb;
    if((la > rb) || (lb > ra)){
      cout << 1 << endl;
    }
    else{
      int count = (min(ra,rb) -max(la, lb));
      if(ra != rb){
        count++;
      }
      if(la != lb){
        count++;
      }
      cout << count << endl;
    }
  }

}


