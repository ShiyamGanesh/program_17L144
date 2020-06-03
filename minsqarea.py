for _ in range(int(input())):
    n=int(input())
    l1,l2=[],[]
    for _ in range(n):
        a,b=map(int,input().split())
        l1.append(a)
        l2.append(b)
    print(max(abs(max(l1)-min(l1)),abs(max(l2)-min(l2)))**2)
