def highest_set_bit_position(x):
    if x == 0:
        return 0
    return x.bit_length() - 1

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    idx = 1
    for _ in range(t):
        l = int(data[idx])
        r = int(data[idx+1])
        idx += 2
        m = l ^ r
        k = highest_set_bit_position(m)
        max_xor = (1 << (k + 1)) - 1
        a = r
        b = r ^ max_xor
        c = l
        print(a, b, c)

if __name__ == "__main__":
    solve()