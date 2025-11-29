import sys
import bisect

def solve():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    t = int(input_data[0])
    pos = 1
    results = []
    for _ in range(t):
        n = int(input_data[pos])
        pos += 1
        # Read 2*n numbers for the sequence b.
        b_list = list(map(int, input_data[pos:pos + 2*n]))
        pos += 2*n
        # We need fast lookup to ensure our extra number d is not in b.
        b_set = set(b_list)
        b_list.sort()

        # Helper: Given two groups (of length n each) and their sums, decide which group has the larger sum.
        # We will then set a1 = difference and output interleaving with the larger sum group first.
        def output_from_groups(group1, group2, sum1, sum2):
            if sum1 >= sum2:
                d = sum1 - sum2
                X, Y = group1, group2
            else:
                d = sum2 - sum1
                X, Y = group2, group1
            # a1 must be at least 1 and distinct from the others.
            if d == 0 or d in b_set:
                return None
            res = [d]
            # Interleave: a2, a3, a4, a5, … where a2,a4,… come from the larger-sum group.
            for x, y in zip(X, Y):
                res.append(x)
                res.append(y)
            return res

        # Option 1: natural partition: first n elements and last n elements.
        A = b_list[:n]  # candidate for the smaller-sum group
        B = b_list[n:]  # candidate for the larger-sum group
        sumA = sum(A)
        sumB = sum(B)
        ans = output_from_groups(B, A, sumB, sumA)
        if ans is not None:
            results.append(" ".join(map(str, ans)))
            continue

        # Option 2: alternate partition: even-indexed vs odd-indexed in sorted order.
        A_alt = b_list[::2]
        B_alt = b_list[1::2]
        sumA_alt = sum(A_alt)
        sumB_alt = sum(B_alt)
        ans = output_from_groups(B_alt, A_alt, sumB_alt, sumA_alt)
        if ans is not None:
            results.append(" ".join(map(str, ans)))
            continue

        # Option 3: try to adjust by swapping one element from A with one from B.
        # Here A and B are from the natural partition.
        found = False
        # Our current difference is:
        d = sumB - sumA  # (we know d is in b_set at this point)
        # For each candidate x in A, we look for y in B that changes the difference:
        # After swapping x (from A) and y (from B):
        # new_sumA = sumA - x + y, new_sumB = sumB - y + x, and new difference d_new = |d - 2*(y-x)|
        for i in range(n):
            x = A[i]
            # Our ideal candidate is when y - x is roughly d/2.
            target = x + d / 2.0
            pos_y = bisect.bisect_left(B, target)
            for candidate in [pos_y - 1, pos_y]:
                if 0 <= candidate < n:
                    y = B[candidate]
                    new_d = abs(d - 2*(y - x))
                    if new_d == 0 or new_d in b_set:
                        continue
                    # Perform swap in local copies.
                    A[i], B[candidate] = B[candidate], A[i]
                    sumA_new = sumA - x + y
                    sumB_new = sumB - y + x
                    candidate_ans = output_from_groups(B, A, sumB_new, sumA_new)
                    if candidate_ans is not None:
                        results.append(" ".join(map(str, candidate_ans)))
                        found = True
                        break
                    # Revert the swap if not working.
                    A[i], B[candidate] = x, y
            if found:
                break

        # According to the problem constraints, a solution always exists.
        if not found:
            # This branch should not be reached.
            results.append("No solution found")
    sys.stdout.write("\n".join(results))


if __name__ == '__main__':
    solve()
