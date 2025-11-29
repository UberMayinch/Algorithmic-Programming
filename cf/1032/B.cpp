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
   vector<bool>c(26, false);
   int n;
   cin >> n;
   string s;
   cin >> s;
   int flag=false;
   c[int(s[0]-'a')] = true;
   c[int(s[n-1]-'a')] = true;
   for(int i=1;i<n-1;i++){
    if(c[int(s[i]-'a')]){
        flag = true;
        break;
    }
    else c[int(s[i]-'a')] = true;
   } 
   if(flag) cout << "YES" << endl;
   else cout << "NO" << endl;
  }
}