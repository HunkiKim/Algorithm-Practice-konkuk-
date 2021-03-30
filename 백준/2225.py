from itertools import permutations, product

def func(arr, N):
    value = 0
    value = sum(arr)
    if value != N:
        return False
    else:
        return True




N , K = input().split()
N , K =  int(N), int(K)
count = 0
Arr = [i for i in range(N+1)]

for i in product(Arr,repeat = K):
    if func(i, N) == True:
        count += 1



print(count)
