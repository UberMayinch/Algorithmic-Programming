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
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    int flag=0;
    int idx=0;
    for(int i=0;i<n-1;i++){
      if(v[idx+1]>=v[idx]){
        idx++;
      }
    }
    for(int i=idx+1;i<n-1;i++){
      if(v[i+1] >= v[i]){
        continue;
      }
      else{
        flag = 1;
        break;
      }
    }

    if(flag == 1){
      cout << "NO" << endl;
    }
    else {
      if((idx != n-1) && (v[n-1] <= v[0])){
        cout << "YES" << endl;
      }
      else if(idx == n-1){
        cout << "YES" << endl;
      }
      else cout << "NO" << endl;
    }
  }

}


