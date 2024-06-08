#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n; // You forgot to take input for n
    vi b(n);
    vi c(n);
    for(int i=0;i<n;i++){
      cin >> b[i];
    }
    for(int i=0;i<n;i++){
      cin >> c[i];
    }
    multiset <int> v; // You didn't specify the data type for the set
    multiset <int> checked;
    for(int i=0;i<n;i++){
      if(b[i] != c[i]){
        v.insert(c[i]);
      }
      else{
        checked.insert(c[i]);
      }
    }
    int w;
    cin >> w;
    vi d(w);
    int flag=0;
    for(int i=0;i<w;i++){
      cin >> d[i];
      if(v.find(d[i]) != v.end()){ 
        auto itr = v.find(d[i]);
        v.erase(itr);
        checked.insert(d[i]);
        flag=0;
      }
      else if(checked.find(d[i]) == checked.end()){
        flag=1;
      }
      else if(checked.find(d[i]) != checked.end() && flag){
        flag=0;
      }
    }
    
    if(v.empty() && flag == 0){
      cout << "Yes" << endl;

    }
    else cout << "No" << endl;
  }
}
