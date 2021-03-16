# 한수 (x,y)  오른쪽위 w,h
x,y,w,h = input().split()


print(min(int(x),int(y),(int(w)-int(x)),(int(h)-int(y))))