#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

ll mod_pow(ll a, ll e) {
ll res = 1 % MOD;
a %= MOD;
while (e) {
if (e & 1) res = (res * a) % MOD;
a = (a * a) % MOD;
e >>= 1;
}
return res;
}

ll mod_inv(ll a) {
return mod_pow(a, MOD - 2);
}

bool mul_exceeds(ll a, ll b, ll limit) {
if (a == 0) return false;
return b > limit / a;
}


vector<int> primes;
bool SEIVE = false;

void seive(int limit = 1e7) {
if (SEIVE) return;
vector<bool> is_composite(limit + 1, false);
for (int i = 2; 1LL * i * i <= limit; ++i) {
if (!is_composite[i]) {
for (long long j = 1LL * i * i; j <= limit; j += i)
is_composite[(int)j] = 1;
}
}
for (int i = 2; i <= limit; ++i)
if (!is_composite[i]) primes.push_back(i);
SEIVE = true;
}


vector<pair<ll, int>> factorize(ll n) {
vector<pair<ll, int>> factors;
for (int p : primes) {
if (1LL * p * p > n) break;
if (n % p == 0) {
int cnt = 0;
while (n % p == 0) {
n /= p;
++cnt;
}
factors.emplace_back(p, cnt);
}
}
if (n > 1) factors.emplace_back(n, 1);
return factors;
}


vector<ll> num_sols(ll N, int exp) {
vector<ll> fact(exp + 1), invfact(exp + 1), comb(exp + 1);
fact[0] = 1;
for (int i = 1; i <= exp; ++i) fact[i] = fact[i - 1] * i % MOD;
invfact[exp] = mod_inv(fact[exp]);
for (int i = exp; i > 0; --i)
invfact[i - 1] = invfact[i] * i % MOD;

comb[0] = 1;
ll running = 1;
ll base = (N - 1) % MOD;
for (int k = 1; k <= exp; ++k) {
    running = (running * ((base + k) % MOD)) % MOD;
    comb[k] = (running * invfact[k]) % MOD;
}
return comb;
}


void dfs(
int idx,
ll cur_prod,
ll cur_ways,
const vector<ll>& primes,
const vector<int>& exps,
const vector<ll>& comb,
ll A,
ll& ans
) {
if (idx == primes.size()) {
ans = (ans + cur_ways) % MOD;
return;
}

ll p = primes[idx];
int E = exps[idx];
ll val = cur_prod;

for (int e = 0; e <= E; ++e) {
    if (val > A) break;

    ll ways = cur_ways;
    ways = (ways * comb[e]) % MOD;       
    ways = (ways * comb[E - e]) % MOD;   

    dfs(idx + 1, val, ways, primes, exps, comb, A, ans);

    if (mul_exceeds(val, p, A)) break;
    val *= p;
}

}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

seive(); 

ll t;
cin >> t;

for (int tc = 1; tc <= t; ++tc) {
    ll n,a,b;
    cin >> n >> a >> b;

    auto factors = factorize(b);

    vector<ll> primes;
    vector<int> exps;
    int exp = 0;

    for (auto& [p, e] : factors) {
        primes.push_back(p);
        exps.push_back(e);
        exp = max(exp, e);
    }

    vector<ll> comb = num_sols(n, exp);

    ll ans = 0;
    dfs(0, 1, 1, primes, exps, comb, a, ans);

    cout << "Case #" << tc << ": " << ans % MOD << '\n';
}

return 0;

}
