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
    vi exp(33);
    for(int i=32;i>=0;i--){
      ll val = ll(pow(2, i));
      exp[i]=val; 
    }
  while(t--){
    ll n;
    cin>> n;
    vi v(33);
    int idx=0;
    for(int i=32;i>=0;i--){
      if(n >= exp[i]){
        n -= exp[i];
        v[i]=1;
        idx=max(idx, i);
      }
    }
    for(int i=0;i<=idx;i++){
      if((v[i] == 2) && (v[i+1] == 2)){
        v[i]=0;
        v[i+1]=1;
        v[i+2]+=1;
      }
      if((v[i] == 2) && (v[i+1] == 0)){
        v[i+1]=1;
        v[i]=0;
      }
      if((v[i] == 2) && (v[i+1] == 1)){
        v[i]=0;
        v[i+1]+=1;
      }
      if((v[i] == 1) && (v[i+1] == 1)){
        v[i+2] += 1;
        v[i] =-1;
        v[i+1]=0;
      }
    }
    for(int i=32;i>=0;i--){
        if(v[i] != 0){
         idx=max(idx, i);
      }
    }
    cout << idx + 1<< endl;
    for(int i=0;i<=idx;i++){
      cout << v[i] << " ";
    }
    cout << endl;
  }

}


