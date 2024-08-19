
MOD = 10**9 + 7

def count_valid_subsequences(binary_sequence, k):
    n = len(binary_sequence)
    count_ones = binary_sequence.count(1)
    
    min_ones = (k + 1) // 2
    
    dp = [[0] * (count_ones + 1) for _ in range(k + 1)]
    dp[0][0] = 1
    
    for bit in binary_sequence:
        if bit == 1:
            for i in range(k, 0, -1):
                for j in range(count_ones, 0, -1):
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD
        else:
            for i in range(k, 0, -1):
                for j in range(count_ones + 1):
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD
    
    result = sum(dp[k][j] for j in range(min_ones, count_ones + 1)) % MOD
    
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

