#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vi v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());
  vi b(m);
  for(int i=0;i<m;i++){
    cin >> b[i];
  }
  sort(b.rbegin(), b.rend());
  int count=0;
  int idx_v=0;
  int idx_b=0;
  while(idx_b < m && idx_v < n){
    if((v[idx_v] >= b[idx_b] - k) && (v[idx_v] <= b[idx_b]+k)){
      count++;
      idx_v++;
      idx_b++;
    }
    else if(v[idx_v] > b[idx_b]){
      idx_v++;
    }
    else if(v[idx_v] < b[idx_b]){
      idx_b++;
    }
  }
  cout << count << endl;
  

}


