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
    int count=0;
    for(int i=0;i<n-1;i++){
      if(v[i+1] > 2*v[i]){
        int j=2;
        while(v[i+1] > j*v[i]){
          count++;
          j*=2;
        }
      }
      else if(2*v[i+1]<v[i]){
        int j=2;
        while(v[i] > v[i+1]*j){
          count++;
          j*=2;
        }

      }
      
    }
    cout << count << endl;

  }

}


