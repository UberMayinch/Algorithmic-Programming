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
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
      if(v[i] % 3 == 0){
        count0++;
      }
      else if(v[i]%3 == 1){
        count1++;
      }
      else{
        count2++;
      }
    }
    int ans=0;
    int dist0 = (count0-n/3);
    int dist1 = (count1-n/3);
    int dist2 = (count2-n/3);

    while(!(dist1 == 0 && dist2 == 0 && dist0 == 0)){
    if(dist0 > 0){
      dist1+=dist0;
      ans+=dist0;
      dist0=0;
    }
    if(dist1 > 0){
      dist2 +=dist1;
      ans+=dist1;
        dist1=0;
    }
    if(dist2 > 0){
        dist0 += dist2;
        ans+=dist2;
        dist2=0;
      }
    }
    cout << ans << endl;
  }

}


