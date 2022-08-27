lst = []
n = int(input())
for i in range(0, n):
    ele = input()
    lst.append(ele)

for x in lst:
    if len(x) > 10:
        print(x[0]+str(len(x)-2)+x[-1])
    else:
        print(x)

