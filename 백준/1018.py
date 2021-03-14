X,Y = input().split()


X,Y = int(Y),int(X)


cx = 0
cy = 0
count = 0
ans = 1000000
Bs = "BWBWBWBW"
Ws = "WBWBWBWB"
B = [[0 for _ in range(Y)] for _ in range(X)]
Li = list()

for i in range(0,Y):
    Li.append(input())

Bboard = list()
for i in range(0,8):
    if i%2 == 0:
        Bboard.append(Bs)
    else:
        Bboard.append(Ws)
Wboard = list()
for i in range(0,8):
    if i%2 == 0:
        Wboard.append(Ws)
    else:
        Wboard.append(Bs)

ans1 = 0
ans2 = 0
ans = 100000
Wboard = [[0 for _ in range(8)] for _ in range(8)]
for i in range(0,X-7):
    for j in range(0,Y-7):
        for x in range(0,8):
            for y in range(0, 8):
                if Bboard[y][x] != Li[j+y][i+x]:
                    ans1 += 1
                elif Wboard[y][x] != Li[j+y][i+x]:
                    ans2 += 1
        
        ans = min(ans1,ans2,ans)
        ans1 = 0
        ans2 = 0


print(ans,end="")