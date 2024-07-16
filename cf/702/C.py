import sys
input = sys.stdin.read

def main():
    data = input().split()
    t = int(data[0])
    queries = list(map(int, data[1:t+1]))

    LIMIT = 10**12
    cubes = set()

    for x in range(1, 10000):
        for y in range(1, 10000):
            value = (x + y) * (x * x - x * y + y * y)
            if value > LIMIT:
                break
            cubes.add(value)

    results = []
    for n in queries:
        if n in cubes:
            results.append("YES")
        else:
            results.append("NO")
    
    print("\n".join(results))

if __name__ == "__main__":
    main()
