from itertools import permutations

L,C = input().split()

L = int(L)
C = int(C)

S = input().split()

Ans = list()

mc = 0
jc = 0


permute = permutations(S,L)

for i in permute:
    mc = i.count('a')
    mc += i.count('e')
    mc += i.count('i')
    mc += i.count('o')
    mc += i.count('u')

    jc = L-mc

    if mc >= 1 and jc >= 2:
        Ans.append(i)
    mc = 0
    jc = 0

RA = list()
for i in Ans:
    for j in range(0,L):
        if j==L-1:
            RA.append(i)
            break
        if i[j] > i[j+1]:
            break

    

RA.sort()



for i in RA:
    print("".join(i))


arr2 = list()
for i in arr1:
    if i%2 == 0:
        arr2.append(i)