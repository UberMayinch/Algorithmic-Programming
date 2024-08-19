#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
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
        cin >> n;
        vi v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        vi pref(n+1);
        pref[0] = 0;
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i-1] + v[i-1];
        }
        string s;
        cin >> s;
        vi li;
        vi ri;
        int l = 0;
        int r = n-1;
        while(l <= r){
            if(s[l] == 'L' && s[r] == 'R'){
                li.pb(l);
                ri.pb(r);
                l++;
                r--;
            }
            else if(s[l] == 'L'){
                r--;
            }
            else if(s[r] == 'R'){ 
                l++;
            }
            else{
                l++;
                r--;
            }
        }
        ll sum = 0;
        for(int i = 0; i < li.size(); i++){
            sum += pref[ri[i]+1] - pref[li[i]]; 
        }
        cout << sum << endl;
    }
}
