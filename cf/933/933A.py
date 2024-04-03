t = int(input())

for _ in range(t):
    n, m, k = map(int, input().split())
    v1 = list(map(int, input().split()))
    v2 = list(map(int, input().split()))

    v1.sort()
    v2.sort()

    count = 0
    idx1 = 0
    idx2 = 0

    while idx1 < n and idx2 < m:
        if v1[idx1] + v2[idx2] < k:
            count += 1
            if idx1 + 1 < n and (idx2 + 1 >= m or v1[idx1 + 1] - v1[idx1] > v2[idx2 + 1] - v2[idx2]):
                idx1 += 1
            else:
                idx2 += 1
        else:
            break

    print(count)
