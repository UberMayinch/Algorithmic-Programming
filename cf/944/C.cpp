#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;

int main(){
  ll t;
  cin >> t;
  while(t--){
    int a, b, c , d;
    cin >> a >> b >> c >> d;
    vi v1(2);
    v1[0]=a;
    v1[1]=b %12;
    sort(v1.begin(), v1.end());
    vi v2(2);
    v2[0]=c;
    v2[1]=d % 12;
    sort(v2.begin(), v2.end());
    if((v2[1]>v1[0])&&(v1[0] > v2[0]) &&(v1[1] > v2[1])){
      cout << "YES" << endl;
    }
    else if((v1[1] > v2[0])&&(v1[0] < v2[0]) && (v1[1] < v2[1])){
      cout << "YES" << endl;
    }
    else cout << "NO" << endl;
  }
}



