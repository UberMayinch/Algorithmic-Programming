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
        int l, r, k;
        cin >> l >> r >> k;
        int allowed = (10 + k - 1) / k;
        if(k > 10) {
            allowed = 0;
        }
        ll count = 1; 
        ll sub=1;
        for(int i = 0; i < r; i++) {
            if(i == l){
            sub = count;
            }
            count = (count * allowed) % MOD; 
        }
        count = (count - sub + MOD) % MOD;
        cout << count << endl; 
    }
    return 0;
}
