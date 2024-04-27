#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve(){

}

int main(){
  int t;
  cin >> t;
  while(t--){
    int k, q;
    cin >> k >> q;
    vi v(k);
    for(int i=0;i<k;i++){
      cin >> v[i];
    }
   vi v2(q); 
    for(int i=0;i<q;i++){
      cin >> v2[i];
    }
    for(int i=0;i<q;i++){
    cout << min(v[0]-1, v2[i]) << " ";
    }
    cout << endl;
  }
}

