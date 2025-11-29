import operator

weights = {}

idx = 1
cnt = 0

with open ("1.txt") as f:
    for line in f:
        if line.strip() == "":
            weights[idx] = cnt
            cnt = 0
            idx+=1
        else:
            cnt += int(line.strip())

max_value = max(weights.items(), key=operator.itemgetter(1), reverse=True)[:3]

print(max_value)

max_values = sorted(weights.items(), key=operator.itemgetter(1), reverse=True)[:3]
sum = 0
for mx in max_values:
    sum += mx[1]
print(sum)