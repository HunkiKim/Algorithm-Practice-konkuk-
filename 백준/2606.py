from collections import deque

def DFS( Dic ,S ,C ):
    for x in Dic:
        if S in C:
            continue
        else:
            C.append(S)
            for y in Dic[S]:
                if y in C:
                    continue
                else: 
                    S = y
                    DFS(Dic,S,C)

Dic = {}

A = int(input())
B = int(input())
for x in range(B):  
    C ,D = map(int,input().split())
    if C in Dic:
        Dic[C].append(D)
    else:
        L = list()
        L.append(D)
        Dic[C] = L
    if D in Dic:
        Dic[D].append(C)
    else:
        L = list()
        L.append(C)
        Dic[D] = L
C = list()
S = 1
DFS(Dic,S,C)

print(len(C)-1)
        
