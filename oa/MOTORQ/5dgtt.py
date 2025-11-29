import sys
import threading
def main():
    import sys
    input = sys.stdin.readline

    # --- 1) Read input and flatten readings ---
    N, D = map(int, input().split())
    A = []
    for vid in range(1, N+1):
        row = list(map(int, input().split()))
        for eff in row:
            A.append((eff, vid))
    # sort all (eff, vid) descending by eff
    A.sort(reverse=True, key=lambda x: x[0])

    Q = int(input())
    queries = []
    for qi in range(Q):
        T = int(input())
        queries.append((T, qi))
    # sort queries descending by T
    queries.sort(reverse=True, key=lambda x: x[0])

    # --- 2) Segment tree over vehicles 1..N storing (count, -vid) max ---
    size = 1
    while size < N:
        size <<= 1
    # tree nodes: store tuples (cnt, -vid)
    tree = [(0, -i) if 1 <= i <= N else (0, 0)
            for i in range(size)] \
         + [(0, -i) if 1 <= i-size <= N else (0, 0)
            for i in range(size, 2*size)]

    # build internal nodes
    for p in range(size-1, 0, -1):
        left, right = tree[p<<1], tree[p<<1|1]
        tree[p] = left if left >= right else right

    def update(vid):
        """Increment the count for vehicle vid by 1."""
        # leaf index in tree
        p = size + (vid - 1)
        cnt, _ = tree[p]
        tree[p] = (cnt+1, -vid)
        # bubble up
        p >>= 1
        while p:
            left, right = tree[p<<1], tree[p<<1|1]
            tree[p] = left if left >= right else right
            p >>= 1

    # --- 3) Sweep to answer queries ---
    ans = [0] * Q
    ai = 0      # pointer in A
    M = len(A)
    for T, qi in queries:
        # add all readings with eff >= T
        while ai < M and A[ai][0] >= T:
            _, vid = A[ai]
            update(vid)
            ai += 1
        # tree[1] = (best_count, -best_vid)
        _, neg_vid = tree[1]
        ans[qi] = -neg_vid

    # --- 4) Output in original query order ---
    print('\n'.join(map(str, ans)))

if __name__ == "__main__":
    # avoid recursion limits on large inputs
    threading.Thread(target=main).start()
