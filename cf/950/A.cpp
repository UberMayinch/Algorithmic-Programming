#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
   int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vi v(7);
    for(int i=0;i<n;i++){
      v[s[i]-'A']++;
    }
    int count=0;
    for(int i=0;i<7;i++){
      count+=max(m-v[i],0);
    }
    cout << count << endl;
  }

}


