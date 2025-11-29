import sys
from collections import deque

def main():
    input = sys.stdin.readline
    N = int(input())
    eff = list(map(int, input().split()))
    K = int(input())

    ans = [0]*N
    dq  = deque()

    # ——— Seed for day 0 over exactly 1..min(N-1,K) ———
    last = min(N-1, K)
    for j in range(1, last+1):
        while dq and eff[j] >= eff[dq[-1]]:
            dq.pop()
        dq.append(j)

    # ——— Now slide from day 0 up to day N-1 ———
    for i in range(N):
        # 1) record
        ans[i] = eff[dq[0]] if dq else 0

        # 2) evict outgoing index = i+1
        if dq and dq[0] == i+1:
            dq.popleft()

        # 3) add incoming index = i+K+1 (if in bounds)
        new_idx = i + K + 1
        if new_idx < N:
            while dq and eff[new_idx] >= eff[dq[-1]]:
                dq.pop()
            dq.append(new_idx)

    print(*ans)

if __name__ == "__main__":
    main()
