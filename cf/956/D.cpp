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
    vi ans(6);
    vi a(n);
    vi b(n);
    vi c(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    for(int i=0;i<n;i++){
      cin >> b[i];
    }
    for(int i=0;i<n;i++){
      cin >> c[i];
    }
    vi apref(n+1);
    vi bpref(n+1);
    vi cpref(n+1);
    //calculate prefix sums for a, b, c;

    sum = (apref[n]+2)/3;
    ans[0]=1;
    {
      int i;
      for(i=0;i<n;i++){
        if(apref[i] > sum){
          ans[1]=i+1;
          break;
        }
      }
      int offset=i;
      ans[2]=ans[1]+1;{
        for(int i=offset;i<n;i++){
          if(bpref[i]-bpref[offset] > sum){
            ans[3]=i+1;
            offset=i;
            break;
          }
        }
      ans[4]=offset+1;
      if(cpref[n+1]-cpref[offset] > sum){
          flag=1;
          break;
        }
      }
      if(flag != 1){
      ans[4]=ans[1]+1;{

      }
      }
      
    }
    if(flag != 1){
      ans[2]=1;
    {
      for(i=0;i<n;i++){
        if(bpref[i] > sum){
          ans[1]=i+1;
          break;
        }
      }
      int offset=i;
      ans[0]=ans[1]+1;{
        for(int i=offset;i<n;i++){
          if(apref[i]-apref[offset] > sum){
            ans[1]=i+1;
            offset=i;
            break;
          }
        }
      ans[4]=offset+1;
      if(cpref[n+1]-cpref[offset] > sum){
          flag=1;
          break;
        }
      else{
            ans[4]=ans[0];
            for(int i=ans[4];i<n;i++){
              if(cpref[i]-cpref[ans[4]] > sum){
                ans[5]=i+1;
                offset=i;
                break;
              }
            }
            ans[0]=offset+1;
            if(apref[n+1]-apref[offset] > sum){
              flag = 1;
              break;
            }
          }
      }
      if(flag != 1){
      ans[4]=ans[1]+1;{

      }
      }
      
    }

      if(flag != 1){
        ans[4]=1;
      }
    }

    if(flag != 1){
      cout << "-1";
    }
    else{
    for(auto it: ans){
      cout << it << " ";
    }}
    cout << endl;
  }

}


