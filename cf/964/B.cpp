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
    vi a(2);
    vi b(2);
    for(int i=0;i<2;i++){
      cin >> a[i];
    }
    for(int i=0;i<2;i++){
      cin >> b[i];
    }
    int count=0;
    if(a[0] > b[0] && a[1] >= b[1]){
      count+=2;
    }
    else if(a[0] == b[0] && a[1] > b[1]){
      count+=2;
    }
    if(a[0] > b[1] && a[1] >= b[0]){
      count+=2;
    }
    else if(a[0] == b[1] && a[1] > b[0]){
      count+=2;
    }
    cout << count << endl;

  }

}


