
def round_score(a, b):
    match (a, b):
        case ('A', 'Y'):
            return 8
        case ('A', 'X'):
            return 4
        case ('A', 'Z'):
            return 3
        case ('B', 'X'):
            return 1
        case ('B', 'Y'):
            return 5
        case ('B', 'Z'):
            return 9
        case ('C', 'X'):
            return 7
        case ('C', 'Y'):
            return 2
        case ('C', 'Z'):
            return 6
        case _:
            return 0

def round_score_2(a, b):
    match (a, b):
        case ('A', 'Y'):
            return 4
        case ('A', 'X'):
            return 3
        case ('A', 'Z'):
            return 8
        case ('B', 'X'):
            return 1
        case ('B', 'Y'):
            return 5
        case ('B', 'Z'):
            return 9
        case ('C', 'X'):
            return 2
        case ('C', 'Y'):
            return 6
        case ('C', 'Z'):
            return 7
        case _:
            return 0
sum = 0
with open('2.txt') as file:
    for line in file:
        sum += (round_score_2(line.split()[0], line.split()[1]))
    print(sum)

# print("A B\n".split()[0])
# print("A B\n".split()[1])
    
    
        