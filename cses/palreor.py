import string

str=list(input())
#print(str)
letters= string.ascii_uppercase
#print(letters)
letter_map = {letter: 0 for letter in letters}

for alp in str:
    letter_map[alp]+=1

#print(letter_map.values())
values_lst=list(letter_map.values())

odd = 0
for val in values_lst:
    if val % 2 == 1 and len(values_lst) % 2 == 0:
        print("NO SOLUTION")
        odd += 1
        break
    elif val % 2 == 1 and odd == 1:
        print("NO SOLUTION")    
        break 
    else:
        if val % 2 == 0:
            val = val / 2
ans = ""

for i in range(1, 26):
    
    if values_lst[i] % 2 != 1:
        ans += letters[i]*values_lst[i] 
    
ans += ans[::-1]
print(ans)

