n = int(input())

L = []
L2 = []
for i in range(0, n):
    L.append(input())





for i in range(0, n):
    for j in range(i+1, n):
        if len(L[i]) > len(L[j]):
            L[i],L[j] = L[j], L[i]
        elif len(L[i]) == len(L[j]):
            if L[i]>L[j]:
                L[i],L[j] = L[j], L[i]
        

for i in range(0,n):
    if i != n-1:
        if L[i]!=L[i+1]:
            print(L[i])
    else:
        print(L[i])
        


