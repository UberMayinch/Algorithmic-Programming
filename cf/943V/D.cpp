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
    int n, k, pa, pb;
    cin >> n >> k >> pa >> pb;
    vi v(n);
    vi p(n);
    for(int i=0;i<n;i++){
      cin >> p[i];
    }
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    vi at(n, -1);
    vi bt(n, -1);
    vi ac(n);
    vi bc(n);
    at[pa-1]=0;
    ac[pa-1]=0;
    bc[pb-1]=0;
    bt[pb-1]=0;
    int i=1;
    int costa=0;
    int costb=0;
    while((i < k) && (i < n)){
      if(at[(p[pa-1])-1]!= -1){
        break;
      }
      if(bt[(p[pb-1])-1]!= -1){
        break;
      }
       at[(p[pa-1])-1]=i;
      bt[(p[pb-1])-1]=i;
      costa += v[pa-1];
      costb += v[pb-1];
      pa=p[pa-1];
      pb=p[pb-1];
      ac[pa-1]=costa;
      bc[pb-1]=costb;
      i++;
    }
    for(int i=0;i<n;i++){
      if(bt[i] != -1){
      bc[i]+=(k-bt[i])*v[i];
      }
      if(at[i] != -1){
      ac[i]+=(k-at[i])*v[i];
      }
    }
    // for(auto it: at){
    //   cout << it << " ";
    // }
    // cout << endl;
    // for(auto it: bt){
    //   cout << it << " ";
    // }
    sort(bc.begin(), bc.end());
    sort(ac.begin(), ac.end());
    if(ac[n-1] > bc[n-1]){
      cout << "Bodya" << endl;
    }
    else if(bc[n-1] > ac[n-1]){
      cout << "Sasha" << endl;
    }
    else cout << "Draw" << endl;
    }
  }


