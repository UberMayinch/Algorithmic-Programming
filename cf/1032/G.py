def run_length_contribution(s):
    n = len(s)
    i = 0
    total = 0
    while i < n:
        ch = s[i]
        j = i
        # Find end of the run of same characters
        while j < n and s[j] == ch:
            j += 1
        length = j - i
        # Contribution of substrings within this run:
        # sum_{l=1 to length} l * (length - l + 1) = length*(length+1)*(length+2)//6
        total += (length * (length + 1) * (length + 2)) // 6
        i = j
    return total

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    t = int(data[idx])
    idx += 1
    results = []
    
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        s = data[idx]
        idx += 1
        res = run_length_contribution(s)
        results.append(str(res))
    
    print("\n".join(results))

if __name__ == "__main__":
    main()
