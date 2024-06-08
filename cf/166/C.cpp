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
    int n, m;
    cin >> n >> m;
    vi a(n+m+1);
    vi b(n+m+1);
    for(int i=0;i<n+m+1;i++){
      cin >> a[i];
    }
    for(int i=0;i<n+m+1;i++){
      cin >> b[i];
    }
    ll t=0;
    ll p=0;
    ll sum=0;
    ll sum2=0;
    vi ans;
    for(int i=1;i<n+m+1;i++){
      if(a[i] > b[i]) && (p < n){
        p++;
        sum+=a[i];
      }
      else if(b[i]>a[i])&&(t < m){
        t++;
        sum+=b[i];
      }
      else if(t==m){
        p++;
        sum+=a[i];
      }
      else if(p == n){
        t++;
        sum+=b[i];
      }
    }
    ans.pb(sum);
    for(int i=0;i<n+m;i++){
      if(a[i+1]>b[i+1] && (a[i]>b[i]){
        sum +=a[i+1]-a[i];
        ans.pb(sum);
      }
      else if(a[i+1]<b[i+1] && (a[i]<b[i]){
        sum +=b[i+1]-b[i];
        ans.pb(sum);
      }
      else{
        if(sum2 != 0){
          
        }
        if(sum2 == 0){
          t=0;
          p=0;
         for(int j=0;j<n+m+1;j++){ 
            if(j != i){
          if(a[j] > b[j]) && (p < n){
        p++;
        sum2+=a[j];
      }
      else if(b[j]>a[j])&&(t < m){
        t++;
        sum2+=b[j];
      }
      else if(t==m){
        p++;
        sum2+=a[j];
      }
      else if(p == n){
        t++;
        sum2+=b[j];
      }
            }
          }
        }
      } 
    }
    cout << sum << endl;

  }

}


