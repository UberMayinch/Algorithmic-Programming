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
        cin >> n;
        vi v(n);
        for(int i=0;i<n;i++){
                cin >> v[i];
        }
        map<ll,vi>s;
        for(int i=0;i<n;i++){
            if(s.find(v[i]+i) != s.end())
                s[v[i]+i].pb(i);
            else
                s[v[i]+i] = {i};
        }
        queue<ll> possible;
        possible.push(n);
        ll mx=0;
        // for(auto it: s){
        //     cout << it.first << ": ";
        //     for(auto il: it.second){
        //         cout << il << " ";
        //     }
        // }
        // cout << endl;
        while(!possible.empty()){
                ll num = possible.front();
                possible.pop();
                // cout << num << endl;
                if(s.count(num)) {
                    for(auto it: s[num]){
                        possible.push(it + num);
                        mx = max(mx, it + num);
                        cout << mx << endl;
                    }
                }
        }
        cout << mx << endl;
    }
}