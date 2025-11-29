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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi v(n);
    for(int i=0;i<n;i++){
        v[i]=s[i]-'0';
    }
    sort(v.begin(), v.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i] == 0){
            cnt++;
        }
    }
    // cout << cnt << endl;
    int cnt_o = n - cnt;
    if((k <= cnt/2 + cnt_o/2) && (k >= abs(cnt/2 - cnt_o/2))){
        if(k % 2 == (cnt/2 + cnt_o/2) % 2)
        cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else cout << "NO" << endl;
    
    // if(cnt % 2){
    //     if(k <= n/2-1 && k % 2 && k >= n/2-1-2*cnt_o){
    //         cout << "YES" << endl;
    //     }
    //     else{
    //         cout << "NO" << endl;
    //     }
    // }
    // else if(cnt % 2 == 0){
    //     if(k <= n/2 && (k % 2 == 0) && k >= n/2 - 2*cnt_o){
    //         cout << "YES" << endl;
    //     }
    //     else cout << "NO" << endl;
    // }
    
  }
}