def swap_chars(str1, str2):
    str1_list = list(str1)
    str2_list = list(str2)
    
    n = len(str2_list)
    j = 0
    while str1_list[j] == str2_list[j]: 
        j += 1
        if j >= n-1:
            break
        
    if n > 1:
        if str1_list[j] > str2_list[j]:
            str1_list, str2_list = str2_list, str1_list


        for i in range(j+1, min(len(str1), len(str2))):
            if str1_list[i] < str2_list[i]:
                str1_list[i], str2_list[i] = str2_list[i], str1_list[i]
    new_str1 = ''.join(str1_list)
    new_str2 = ''.join(str2_list)
    
    return new_str1, new_str2


t = int(input())
for i in range(t):
    str1 = input()
    str2 = input()

    new_str1, new_str2 = swap_chars(str1, str2)
    print(new_str1)
    print(new_str2)
