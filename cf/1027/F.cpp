#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long> vi;
typedef long long ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

// Fast sieve for SPF and omega
const int MAXN = 1000000;
int spf[MAXN+1];
int omega_cnt[MAXN+1];
int bestOmega[MAXN+1];

void init_sieve() {
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    omega_cnt[1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        omega_cnt[i] = omega_cnt[i / spf[i]] + 1;
    }
    bestOmega[0] = 0;
    for (int i = 1; i <= MAXN; i++) {
        bestOmega[i] = max(bestOmega[i-1], omega_cnt[i]);
    }
}

// Factor and check primes > k
bool has_large_prime(int v, int k) {
    while (v > 1) {
        int p = spf[v];
        if (p > k) return true;
        while (v % p == 0) v /= p;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_sieve();

    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        if (x == y) {
            cout << 0 << '\n';
            continue;
        }
        int g = gcd(x, y);
        int a = x / g, b = y / g;
        if (has_large_prime(a, k) || has_large_prime(b, k)) {
            cout << -1 << '\n';
            continue;
        }
        // total exponent difference Δ
        ll delta = 0;
        int ta = a;
        while (ta > 1) {
            int p = spf[ta], cnt = 0;
            while (ta % p == 0) ta /= p, cnt++;
            int cnt2 = 0;
            int tb = b;
            while (tb > 1 && spf[tb] == p) tb /= p, cnt2++; // not correct to get b exponent per prime
            // simpler: factor both with maps, but small a,b <=1e6
            // Instead, use map:
        }
        // easier: do factor maps
        unordered_map<int,int> ma, mb;
        int v;
        v = a;
        while (v>1) { int p=spf[v]; while (v%p==0) v/=p, ma[p]++; }
        v = b;
        while (v>1) { int p=spf[v]; while (v%p==0) v/=p, mb[p]++; }
        for (auto &pr : ma) {
            delta += abs(pr.second - mb[pr.first]);
        }
        for (auto &pr : mb) {
            if (!ma.count(pr.first)) delta += pr.second;
        }
        int M = bestOmega[k];
        ll ops = (M==0 ? (delta==0?0:-1) : (delta + M - 1) / M);
        cout << ops << '\n';
    }
    return 0;
}
