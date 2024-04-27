
MOD = int(1e9) + 7

def count_solutions(z):
    if z == 0:
        return 0
    if z == 1:
        return 1
    if z == 2:
        return 3

    prev_prev = 1
    prev = 3

    for i in range(3, z + 1):
        current = (prev + (2*i-2) * prev_prev) % MOD
        prev_prev, prev = prev, current

    return current

t = int(input())
for _ in range(t):
    z, n = map(int, input().split())
    for _ in range(n):
        r, c = map(int, input().split())
        if r == c:
            z -= 1
        else:
            z -= 2

    result = count_solutions(z)
    print(result)
