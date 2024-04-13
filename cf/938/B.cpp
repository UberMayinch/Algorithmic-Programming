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
    ll n, c, d;
    int flag=0;
    cin >> n >> c >> d;
    vi v(n*n);
    for(int i=0;i<n*n;i++){
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll a=v[0];
    vector <ll> actual(n * n);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        actual[i*n + j] = a + i*c + j*d;
      }
    }
    sort(actual.begin(), actual.end());
    for(int i=0;i<n*n;i++){
      if(actual[i] != v[i]){
        flag = 1;
        break;
      }
    }
    if(flag == 1){
      cout << "NO";
    }
    else{
      cout << "Yes";
    }
    cout << endl;
  }
}

