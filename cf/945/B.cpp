#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
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
    deque <int> sw;
    sw.push_back(v[0]);
    int runor=v[0];
    for(int i=1;i<n;i++){
    cout << sw.front() << (runor ^ ~v[i]) << endl;
     if(runor == (sw.front() | runor ^ ~(v[i]))){
        sw.pop_front();
        sw.push_back(v[i]);
      } 
    else{
        sw.push_back(v[i]);
        runor = runor | v[i];
        cout << runor << endl;;
      }
    }
    cout << sw.size() << endl;
  }

}


