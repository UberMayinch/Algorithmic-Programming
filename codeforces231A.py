n= int(input())
x= 0

for i in range (0,n):
    l = input().replace(" ", "")
    m= int(l)
    if m == 111 or m % 3 == 2:
        x+= 1

print(x)
