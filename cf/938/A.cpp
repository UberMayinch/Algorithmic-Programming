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
    ll n, a ,b;
    cin >> n >> a >> b;
    if(b > 2 * a){
      cout << n * a;
    }
    else{
      cout << (n / 2) * b + (n % 2) * a;
    }
    cout << endl;
  }
}

