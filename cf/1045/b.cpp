#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<bool> is_prime(100001, true);
vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 100000; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (long long j = (long long)i * i; j <= 100000; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

ll modinv(ll a, ll m) {
    ll result = 1;
    ll base = a % m;
    ll exp = m - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        exp /= 2;
    }
    return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vi ans(n);
    
    sieve();
    ll first_prime = 0;
    for(int prime : primes) {
        if(k % prime != 0) {
            first_prime = prime;
            break;
        }
    }
    // cout << first_prime << endl;
    ll kmodp = k % first_prime;
    for(int i = 0;i<n;i++){
        ll vmod = v[i] % first_prime;
        ll x = (-vmod * modinv(kmodp, first_prime)) % first_prime;
        if(x < 0) x += first_prime;
        ans[i] = k * x + v[i];
    }
    for(auto it: ans){
        cout << it << " ";
    } 
    cout << endl;
  }
}