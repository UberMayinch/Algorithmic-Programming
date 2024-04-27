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
    int n;
    cin >> n;
    ll sum=0;
    for(int i=1;i<=n;i++){
      sum+=i*(2*i-1);
    }
    int m=2*n;
    cout << sum << " " << m << endl;
    for(int i=0;i<n;i++){
      cout << 1 << " " << n-i << " "    ;
      for(int j=0;j<n;j++){
        cout << j+1 << " ";
      }
      cout << endl;
      cout << 2 << " " << n-i << " "    ;
      for(int j=0;j<n;j++){
        cout << j+1 << " ";
      }
      cout << endl;
    }
  }
}

