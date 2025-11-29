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
  int n, x;
  cin >> n >> x;
  vi v(n);
  for(int i=0;i<n;i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  ll count=0;
  int l=0,r=n-1;
  while(l <= r){
    if(l == r){
      count++;
      break;
    }
    else if((v[l] + v[r]) <= x){
      count++;
      r--;
      l++;
    }
    else{
      count++;
      r--;
    }
  }
  cout << count << endl;
}


