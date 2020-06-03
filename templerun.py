n=int(input())
l=list(map(int,input().split()))
l.append(0)
for _ in range(int(input())):
    s,c,x=0,0,0
    a=int(input())
    for i in range(n+1):
        if s>=a:
            c+=1
            x=1
            break
        else:
            c+=1
        s+=l[i]
    if x==0 and i==n:
        print(-1)
    else:
        print(c-1)
