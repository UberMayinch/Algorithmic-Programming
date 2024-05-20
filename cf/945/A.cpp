#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int a, b,c;
    cin >> a >> b >> c;
    if (((a % 2)+ (b %2) + (c % 2) == 1) ||  ((a % 2)+ (b %2) + (c % 2) == 3)){
      cout << "-1" << endl;
    } 
    else {
      int count = 0;
      while((c >= b) && (a > 0)){
          c --;
          a--;
          count++;
      }
      int i=0;
      while(a > 0){
        if(i == 0){
        b--;
        i=1;
        }
        else{
       c--;
        i=0;
        } 
        a--;
        count++;
      }
      count += min(b, c);
      cout << count << endl;
    }
  }

}


