#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int spf[MAXN]; // smallest prime factor

void sieve() {
    for (int i = 1; i < MAXN; i++) spf[i] = i;
    
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

bool has_large_prime(int n, int k) {
    while (n > 1) {
        if (spf[n] > k) return true;
        int p = spf[n];
        while (n % p == 0) n /= p;
    }
    return false;
}

int min_operations_to_one(int n, int k) {
    if (n == 1) return 0;
    
    int ops = 0;
    while (n > 1) {
        // Find the largest divisor <= k
        int largest_div = 1;
        
        // Check divisors up to sqrt(n)
        for (int i = 2; i * i <= n && i <= k; i++) {
            if (n % i == 0) {
                largest_div = max(largest_div, i);
                if (n / i <= k) {
                    largest_div = max(largest_div, n / i);
                }
            }
        }
        
        // Check if n itself is <= k
        if (n <= k) {
            largest_div = n;
        }
        
        if (largest_div == 1) {
            return -1; // impossible
        }
        
        n /= largest_div;
        ops++;
    }
    
    return ops;
}

int count_prime_factors(int n) {
    int count = 0;
    while (n > 1) {
        int p = spf[n];
        count++;
        n /= p;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    
    int t;
    cin >> t;
    
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        
        // Check for large prime factors
        if (has_large_prime(x, k) || has_large_prime(y, k)) {
            cout << -1 << "\n";
            continue;
        }
        
        // Find GCD and check if we can use it
        int g = __gcd(x, y);
        
        // We can only use GCD optimization if GCD has no prime factors > k
        if (!has_large_prime(g, k)) {
            x /= g;
            y /= g;
        }
        
        // Calculate operations: reduce x to 1, then build y from 1
        int ops1 = min_operations_to_one(x, k);
        if (ops1 == -1) {
            cout << -1 << "\n";
            continue;
        }
        
        int ops2 = count_prime_factors(y);
        
        cout << ops1 + ops2 << "\n";
    }
    
    return 0;
}