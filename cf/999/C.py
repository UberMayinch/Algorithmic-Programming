import sys
MOD = 998244353

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        a = list(map(int, data[idx:idx+n]))
        idx += n
        dp = {}
        dp[(0, 0)] = 1
        for ai in a:
            new_dp = {}
            for (prev_liar, total_liars), cnt in dp.items():
                if ai == total_liars:
                    key = (0, total_liars)
                    if key in new_dp:
                        new_dp[key] = (new_dp[key] + cnt) % MOD
                    else:
                        new_dp[key] = cnt % MOD
                if prev_liar == 0:
                    key = (1, total_liars + 1)
                    if key in new_dp:
                        new_dp[key] = (new_dp[key] + cnt) % MOD
                    else:
                        new_dp[key] = cnt % MOD
            dp = new_dp
            if not dp:
                break
        res = sum(dp.values()) % MOD if dp else 0
        print(res)

if __name__ == "__main__":
    main()