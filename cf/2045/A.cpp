#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--) {
    string s, t;
    cin >> s; 
    cin >> t;
    map<char, int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]=i+1;
    }
    ll mn=(ll)2e5+1;
    string ans;
    for(int j=t.size()-1;j>=0;j++){
        if(m[t[j]] != 0){
            mn = min(mn, m[t[j]]+(ll)(t.size()-1-j));
        }    
    }
    
  }
}