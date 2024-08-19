
MOD = 10**9 + 7

def mod_inv(x, mod):
    return pow(x, mod - 2, mod)

def precompute_factorials_and_inverses(max_n, mod):
    fact = [1] * (max_n + 1)
    inv_fact = [1] * (max_n + 1)
    
    for i in range(2, max_n + 1):
        fact[i] = fact[i - 1] * i % mod
    
    inv_fact[max_n] = mod_inv(fact[max_n], mod)
    for i in range(max_n - 1, 0, -1):
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod
    
    return fact, inv_fact

def binomial_coefficient(n, k, fact, inv_fact, mod):
    if k > n or k < 0:
        return 0
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod

def count_valid_subsequences(binary_sequence, k):
    n = len(binary_sequence)
    count_ones = binary_sequence.count(1)
    
    min_ones = (k + 1) // 2
    
    fact, inv_fact = precompute_factorials_and_inverses(k, MOD)
    
    dp = [0] * (count_ones + 1)
    dp[0] = 1
    
    for bit in binary_sequence:
        if bit == 1:
            for j in range(count_ones, 0, -1):
                dp[j] = (dp[j] + dp[j - 1]) % MOD
        else:
            new_dp = dp[:]
            for i in range(1, k + 1):
                for j in range(count_ones + 1):
                    new_dp[j] = (new_dp[j] + dp[j]) % MOD
            dp = new_dp
    
    result = sum(dp[j] for j in range(min_ones, count_ones + 1)) % MOD
    
    return result

def main():
    t = int(input().strip())
    
    results = []
    
    for _ in range(t):
        n, k = map(int, input().strip().split())
        binary_sequence = list(map(int, input().strip().split()))
        results.append(count_valid_subsequences(binary_sequence, k))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
