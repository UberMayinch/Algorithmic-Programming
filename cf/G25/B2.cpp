#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve() {}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int count = 0;
    int tofind = v[k - 1];
    int idx=0;
    for(int i=0;i<k;i++){
      if(v[i]>tofind){
        idx=i;
        break;
      }
    }
    v[k-1]=v[idx];
    v[idx]=tofind;
    for (int i = max(idx-1,0); i < n-1; i++) {
      if (max(v[i],v[i+1]) > tofind) {
        break;
      }
      count++;
    }
    cout << max(count, idx-1)  << endl;
  }
}
