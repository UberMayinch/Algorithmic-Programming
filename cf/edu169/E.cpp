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
  vi grundy(10000009, -1);
  grundy[0]=0;
  grundy[1]=1;
  grundy[2]=0;
  for(int i=2;i<10000009;i++){
    if(i % 2 == 0)grundy[i]=0; 
  }
  int count=2;
  for(int i=3;i<10000009;i++){
    if(grundy[i] == -1){
      grundy[i]=count;
      for(int j=2;j*i<10000009;j++){
        if(i*j % 2){
          grundy[i*j]=count;
        }
      }
      count++;
    }
  }
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi v(n);
    int ans=0;
    for(int i=0;i<n;i++){
      cin >> v[i];
      ans ^= grundy[v[i]];
    }

    if(ans == 0){
      cout << "Bob" << endl;
    }
    else cout << "Alice" << endl;
  }

}


