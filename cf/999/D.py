import sys
from collections import deque

def main():
    input = sys.stdin.read().split()
    ptr = 0
    t = int(input[ptr])
    ptr += 1
    for _ in range(t):
        n, m = int(input[ptr]), int(input[ptr+1])
        ptr += 2
        a = list(map(int, input[ptr:ptr+n]))
        ptr += n
        b = list(map(int, input[ptr:ptr+m]))
        ptr += m
        
        sum_a = sum(a)
        sum_b = sum(b)
        if sum_a != sum_b:
            print("No")
            continue
        if not a and not b:
            print("Yes")
            continue
        if not b:
            print("Yes" if not a else "No")
            continue
        max_a = max(a)
        max_b = max(b)
        if max_b < max_a:
            print("No")
            continue
        a.sort()
        b.sort(reverse=True)
        dq = deque(a)
        possible = True
        for target in b:
            if not dq:
                possible = False
                break
            x = dq.pop()
            current = x
            remaining = target - x
            if remaining < 0:
                possible = False
                break
            group = [x]
            # Collect from the back (largest remaining)
            while remaining > 0 and dq:
                next_x = dq.pop()
                if next_x <= remaining:
                    current += next_x
                    remaining -= next_x
                    group.append(next_x)
                else:
                    dq.append(next_x)
                    break
            # Collect from the front if needed
            while remaining > 0 and dq:
                front = dq.popleft()
                if front > remaining:
                    dq.appendleft(front)
                    possible = False
                    break
                current += front
                remaining -= front
                group.append(front)
            if remaining != 0:
                possible = False
            if not possible:
                break
            # Check merge condition
            group.sort()
            s = 0
            valid = True
            for i in range(len(group) - 1):
                s += group[i]
                if s < group[i+1] - 1:
                    valid = False
                    break
            if not valid:
                possible = False
                break
        if possible and not dq:
            print("Yes")
        else:
            print("No")

if __name__ == '__main__':
    main()