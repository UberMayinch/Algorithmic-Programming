MOD = int(1e9) + 7

def count_solutions(z):
    dp = [0] * (z + 1)
    dp[0] = 0  
    dp[1] = 1
    dp[2] = 3    

    for i in range(3, z + 1):
        dp[i] = (dp[i] + (2*i-2)*dp[i - 2]) % MOD
        dp[i] = (dp[i] + dp[i - 1]) % MOD
   
    result = ( dp[z]) % MOD
    
    return result


t = int(input())
for _ in range(t):
    z, n = map(int, input().split())
    for _ in range(n):
        try:
            r, c = map(int, input().split())
            if r == c:
                z -= 1
            else:
                z -= 2
        except ValueError:
            break  
        
    result = count_solutions(z)
    print(result)
