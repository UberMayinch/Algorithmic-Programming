#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

int solve(int n, int x, int y, vi verts){
  int consec=0;
  sort(verts.begin(), verts.end());
  if((verts[n-1]== n) && (verts[0] == 1)){
    consec+=1;
  }
  for(int i=0;i<n-1;i++){
    if(verts[i+1]== verts[i]+1){
      consec++;
    }
  }
  if(consec > n -2){
    return n-2;
  }
  else
  return consec;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, x, y;
    cin >> n >> x >> y;
    vi verts(n);
    for(int i=0;i<n;i++){
      cin >> verts[i];
    }
    cout << solve(n, x, y, verts);
    cout << endl;
  }
}

