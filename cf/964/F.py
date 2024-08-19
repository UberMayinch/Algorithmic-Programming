from math import factorial as fact
from math import comb

MOD = 1000000007

def mod_inv(a, p):
    return pow(a, p-2, p)

def mod_comb(n, k, mod):
    if k > n or k < 0:
        return 0
    num = fact(n)
    denom = fact(k) * fact(n - k) % mod
    return num * mod_inv(denom, mod) % mod

def solve(n, k, v):
    cnt = v.count(1)
    if cnt < (k + 1) // 2 or n - (k + 1) // 2 < (k - 1) // 2:
        return 0
    
    part1 = mod_comb(cnt, (k + 1) // 2, MOD)
    part2 = mod_comb(n - (k + 1) // 2, (k - 1) // 2, MOD)
    return (part1 * part2) % MOD

def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        v = list(map(int, input().split()))
        print(solve(n, k, v))

if __name__ == "__main__":
    main()
