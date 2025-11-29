#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  
            result = ((result % mod) * (base%mod)) % mod;
        }
        base = ((base % mod) * (base%mod)) % mod;  
        exp = exp / 2;  
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi v(n);
        ll sum = 0;
        ll sq = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum = (sum + v[i]) % MOD;
            sq = (sq + ((v[i] * v[i]) % MOD)) % MOD;
        }
        
        ll p = (sum * sum) % MOD;
        p = (p - sq + MOD) % MOD;  
        p = (p * mod_exp(2, MOD-2, MOD)) % MOD;  
        
        ll q = (n*(n-1)) % MOD;
        q = (q * mod_exp(2, MOD-2, MOD)) % MOD;  
        ll q_inv = mod_exp(q, MOD-2, MOD);  
        ll result = (p * q_inv) % MOD;
        
        cout << result << endl;
    }
}
