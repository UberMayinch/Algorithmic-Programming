#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
typedef vector<long long int>vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int x, y;
    cin >> x >> y;
    int count=0;
    if((x > 7) || (y > 2)){
    while(y > 1){
        y -=2;
        x -=7;
        count++;
      }
    if(y == 1){
        y -=1;
        x -= 11;
        count++;
    }
    while(x > 0){
        x-=15;
        count++;
      }
    }
    else if ((x==0) && (y == 0)) count=0;
    else count=1; 
    cout << count<< endl;
  }

}


