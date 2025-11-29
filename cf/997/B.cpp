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
    int n;
    cin >>n ;
    vi ans(n);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int idx=n-1;
        for(int j=0; j<s.size(); j++){
            if(j < i){
                if(s[j]=='0'){
                    idx--;
                }
            }
            else if(j > i){
            if(s[j] == '1'){
                idx--;
            }
            }
        }
        ans[idx]=i+1;
    }
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;

    
  }
}