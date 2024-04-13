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
    ll n, m, k;
    cin >> n >> m >> k;
    ll cei= n/m;
    if(n % m != 0){
      cei+=1;
    }
    if(k >= n - cei){
      cout << "NO";
    }
    else cout << "YES";
    cout << endl;
  }
}

