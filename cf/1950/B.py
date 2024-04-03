t=int(input())

for a in range(t):
    n=int(input())
    for j in range(n):
        for b in range(2):
            for i in range(n):
                if (i+ j) % 2 < 1:
                    print("##", end="")
                else:
                    print("..", end="")
            print("")
        
