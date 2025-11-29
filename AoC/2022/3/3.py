# UNCOMMENT FOR PART 1
sm = 0

with open ('3.txt') as file:
    for line in file:
        idx = len(line)//2
        l1 = line[:idx]
        l2 = line[idx:]
        for char in l1:
            if l2.find(char) != -1:
                if char.isupper():
                    sm += ord(char) - ord('A')+27
                else:
                    sm += ord(char) - ord('a')+1
                break
print(sm)

def process(lst):
    print(lst)
    chars = []
    for char in lst[0]:
        if lst[1].find(char) != -1:
            chars.append(char)
    
    for char in chars:
        if lst[2].find(char) != -1:
            print(char)
            if char.isupper():
                return ord(char) - ord('A') + 27
            else:
                return ord(char) - ord('a') + 1

sm = 0
with open ('3.txt') as file:
    lst_t = []
    for line in file:
        lst_t.append(line.strip())
        if(len(lst_t) == 3):
            sm += process(lst_t)
            lst_t = []

print(sm)