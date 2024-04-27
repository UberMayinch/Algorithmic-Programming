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
flag = 0
for val in values_lst:
    if val % 2 == 1 and len(str) % 2 == 0:
        flag =1
        print("NO SOLUTION")
        break
    if val % 2 == 1 and odd == 0:
        odd +=1
    elif val % 2 == 1 and odd == 1:
        flag =1
        print("NO SOLUTION")    
        break 
ans = ""
rem = -1
for i in range(0, 26):
    
    if values_lst[i] % 2 != 1:
        reps = values_lst[i]//2
        ans += letters[i]*(reps)
    else:
        rem = i

ans2 = ans[::-1]
if rem != -1:
 ans += letters[rem]*values_lst[rem]
ans +=ans2

if flag != 1:
    print(ans)

