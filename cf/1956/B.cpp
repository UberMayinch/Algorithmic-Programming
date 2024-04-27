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
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    int count = 0;
    sort(v.begin(), v.end());
    for(int i=0;i<n-1;i++){
      if(v[i] == v[i+1]){
        count +=1;
      }
    }
    cout << count << endl;
  }
}

