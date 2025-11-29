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
    string s;
    cin >> s;
    string p = s;
    int n = s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]=='p'){
            p[n-1-i]='q';
        }
        else if(s[i]=='q'){
            p[n-1-i]='p';
        }
        else if(s[i] == 'w'){
            p[n-1-i]='w';
        }
    }
    cout << p << endl;
    
  }
}