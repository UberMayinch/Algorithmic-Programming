import random

# Constants
MIN_T = 1
MAX_T = 20
MIN_N = 1
MAX_N = 200
MIN_A = 1

t = random.randint(MIN_T, MAX_T)

with open(f"testcase.txt", "w") as f:
    f.write(str(t) + "\n")
    for tc in range(t):
        n = random.randint(MIN_N, MAX_N)
        arr = [random.randint(MIN_A, n) for _ in range(n)]
        f.write(str(n) + "\n")
        f.write(" ".join(map(str, arr)) + "\n")

print(f"Testcase generated")
