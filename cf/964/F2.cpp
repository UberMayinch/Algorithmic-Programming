#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

// Function to compute x^y % p in O(log y) time
ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Function to compute the modular inverse of a under modulo p
ll modInverse(ll a, ll p) {
    return power(a, p-2, p);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vi fact(200000, 1);
    for(int i = 1; i < fact.size(); i++) {
        fact[i] = ((fact[i-1] % MOD) * (i % MOD)) % MOD;
    }
    ll t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi v(n);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] == 1){
                cnt++;
            }
        }

        // Compute answer using modular inverses
        ll a = fact[cnt];
        ll b = fact[cnt - (k + 1) / 2] * fact[(k + 1) / 2] % MOD;
        ll c = fact[n - (k + 1) / 2] * fact[(k - 1) / 2] % MOD * fact[n - k] % MOD;

        ll ans = a * modInverse(b, MOD) % MOD * modInverse(c, MOD) % MOD;
        cout << ans << endl;
    }
}
