sm = 0
with open('4.txt') as file:

    for line in file:
        # sm += 1
        lst_a = line.strip().split(',')
        l = lst_a[0].split('-')
        r = lst_a[1].split('-')
        if(l[0] >= r[0] and l[1] <= r[1]) or (l[0] <= r[0] and l[1] >= r[1]):
            if not(l[0] == r[0] and l[1] == r[1]):
                print(l)
                print(r)
                sm +=1

print(sm)
