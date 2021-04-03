def DFS(DFSD,Snum,C,Ngasu):
    # print(C)
    if len(C) == Ngasu:
        return
    for x in DFSD[Snum]:
        if x in C:
            if Snum in C:
                continue
            else:
                C.append(Snum)
                continue
        else:
            if Snum in C:
                Snum = x
                DFS(DFSD,Snum,C,Ngasu)
            else:
                C.append(Snum)
                Snum = x
                DFS(DFSD,Snum,C,Ngasu)



def BFS(BFSD,Snum,C,Ngasu):
    # print(C, Snum)
    count = 0
    C.append(Snum)
    while True:
        # print(C)
        if len(C) == Ngasu:
            break
        if count == Ngasu:
            break
        for x in BFSD[Snum]:
            if x in C:
                A
            else:
                C.append(x)

        count += 1
        if len(C)<count+1:
            A
        else:
            Snum = C[count]










Ngasu, Lgasu, Snum = input().split()
Ngasu, Lgasu, Snum = int(Ngasu), int(Lgasu), int(Snum)


Dic = {}


for x in range(1,Ngasu+1):
    L = list()
    Dic[x] = L

for x in range(Lgasu):
    A,B = input().split()
    A,B = int(A), int(B)
    Dic[A].append(B)
    Dic[B].append(A)

for x in Dic:
    Dic[x].sort()

# ---- 여기까지 리스트로 만들기 ------
if len(Dic[Snum]) == 0:
    print(Snum)
    print(Snum)
    exit()
# print(Dic)
DFSL = list()
DFS(Dic,Snum,DFSL,Ngasu)
# print(DFSL)
for x in DFSL:
    print(x,end=' ')
print()
DFSL = list()
BFS(Dic,Snum,DFSL,Ngasu)
for x in DFSL:
    print(x,end=' ')

# print(BFSL)