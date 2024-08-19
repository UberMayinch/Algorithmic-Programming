MOD = 10**9 + 7

def count_valid_subsequences(binary_sequence, k):
    n = len(binary_sequence)
    count_ones = sum(binary_sequence)
    min_ones = (k + 1) // 2
    
    dp = [0] * (k + 1)
    dp[0] = 1
    
    for bit in binary_sequence:
        if bit == 1:
            for i in range(k, 0, -1):
                dp[i] = (dp[i] + dp[i - 1]) % MOD
    
    result = sum(dp[k] for _ in range(min_ones, count_ones + 1)) % MOD
    return result

def main():
    t = int(input().strip())
    
    results = []
    
    for _ in range(t):
        n, k = map(int, input().strip().split())
        binary_sequence = list(map(int, input().strip().split()))
        results.append(count_valid_subsequences(binary_sequence, k))
    
    print(*results, sep='\n')

if __name__ == "__main__":
    main()
