#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<string> s(n);
  int sum=0;
  for(int i=0;i<n;i++){
    int x;
    cin >> s[i] >> x;
    sum +=x;
  }
  sum = sum %n;
  sort(s.begin(), s.end());
  cout << s[sum] << endl;
}


