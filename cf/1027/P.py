import sys
from collections import Counter
import math

sys.setrecursionlimit(1000000)

# Fast prime factorization using trial division
def prime_factors(n):
    i = 2
    factors = Counter()
    while i * i <= n:
        while n % i == 0:
            factors[i] += 1
            n //= i
        i += 1
    if n > 1:
        factors[n] += 1
    return factors

def solve_case(x, y, k):
    if x == y:
        return 0
    fx = prime_factors(x)
    fy = prime_factors(y)

    all_primes = set(fx.keys()).union(fy.keys())
    if any(p > k for p in all_primes):
        return -1

    total_ops = 0
    for p in all_primes:
        total_ops += abs(fx[p] - fy[p])
    return total_ops

t = int(input())
for _ in range(t):
    x, y, k = map(int, input().split())
    print(solve_case(x, y, k))
