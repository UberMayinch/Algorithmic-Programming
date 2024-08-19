
MOD = 10**9 + 7

def count_valid_subsequences(binary_sequence, k):
    # Ensure binary_sequence is a string
    binary_sequence = ''.join(map(str, binary_sequence))
    
    n = len(binary_sequence)
    count_ones = binary_sequence.count('1')
    
    min_ones = (k + 1) // 2
    
    dp = [[0] * (count_ones + 1) for _ in range(k + 1)]
    dp[0][0] = 1
    
    for bit in binary_sequence:
        if bit == '1':
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
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    index = 0
    t = int(data[index])
    index += 1
    results = []
    
    for _ in range(t):
        n, k = map(int, data[index:index + 2])
        index += 2
        v = data[index:index + n]
        index += n
        result = count_valid_subsequences(v, k)
        results.append(result)
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
