import itertools
n = int(input())

k = [i for i in range(1,n)]
def strictly_increasing(lis):
    for i in range(len(lis)-1):
        if lis[i] >= lis[i+1]:
            return False

    return True
count = 0
for item in itertools.combinations(k,3):
    if strictly_increasing(item):
        count += 1

print(count)