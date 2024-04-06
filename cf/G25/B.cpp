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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    int count =0;
    int max_int=min(v[0], v[1]);
    for(int i=1;i<n-1;i++){
      if(max_int < v[i]){
        max_int = v[i];
      } 
      count++;
      if(max_int > v[k-1]){
        break;
      }
    }  
    cout << count << endl;
  }
}

