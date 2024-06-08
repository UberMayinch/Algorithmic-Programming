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
    vi div;
    int count=0;
    for(int i=0;i<n-1;i++){
      div.pb(gcd(v[i], v[i+1]));
    }
    
    int lst=0;
    for(int i=0;i<n-2;i++){
      if(div[i+1] < div[i]){
        lst=i;
        break;
      }
    }
    vi div2;
    vi div3;
    int j;
    for(int i=0;i<n-1;i++){
      j=i+1;
      if(i+1 == lst){
        j++;
      }
      if(i == lst){
        continue;
      }
      div2.pb(gcd(v[i], v[j]));
    }
    for(int i=0;i<n-1;i++){
      j=i+1;
      if(i == lst){
        j++;
      }
      if(i-1 == lst){
        continue;
      }
      div3.pb(gcd(v[i], v[i+1]));
    }

    for(int i=0;i<n-2;i++){
      if(div2[i+1] < div2[i]){
        count++;
        break;
      }
    }
    if(!count){

    for(int i=0;i<n-2;i++){
      if(div3[i+1] < div3[i]){
        count++;
        break;
      }
    }
    }
    // for(auto it: div){
    //   cout << it << " ";
    // }
    // cout << endl;
    // cout << lst << endl;
    // cout << count << endl;
    if(count == 0){
      cout << "YES" << endl;
    } 
    else cout << "NO" << endl;
  }

}


