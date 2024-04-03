#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve(){

}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll a, b, c;
    cin >> a >> b >> c;
    if((a < b) && (b < c)){
      cout << "STAIR";
    }
    else if((a < b) && (b > c)){
      cout << "PEAK";
    }
    else{
      cout << "NONE";
    }
    cout << endl;
  }
}

