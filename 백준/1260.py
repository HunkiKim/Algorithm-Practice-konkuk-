

def Node(key, adj,g):
    a = list()
    
    key = int(key)
    if key in g: # 그래프 넣기
        a = g[key]
        a.append(int(adj))
        g[key] = a
    else:
        a.append(int(adj))
        g[key] = a

    if adj in g: # key로 들어오지 않은 key값 추가 
        a
    else:
        g[int(adj)] = list()

def DFS(g,snum, nodegasu):
    check = list()
    start = snum
    count = 1
    
    while True:
        
        if len(check)==nodegasu:
            break
        if len(g[start])!=0:
            if start in check:
                start = g[start].pop()
                continue
            print(start, ' ', end='')
            check.append(start)
            start = g[start].pop()
            count=1
        else:
            if start in check:
                start = check[len(check)-count]
                count += 1
                continue
            print(start,' ', end='')
            check.append(start)
            start=check[len(check)-count]
            count+=1
        
    
                
    

            



g = {}
chec = list()
nodegasu, linegasu, startnum = input().split()
nodegasu, linegasu, startnum = int(nodegasu), int(linegasu), int(startnum)

for x in range(linegasu): # 그래프 넣기
    node,adj = input().split()
    Node(node,adj,g)

#숫자들 정렬
for x in g:
    g[x].sort()
    g[x].reverse()

#dfs
DFS(g,startnum,nodegasu)
# print(g[1].pop())











