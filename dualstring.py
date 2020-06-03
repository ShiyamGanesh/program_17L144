for _ in range(int(input())):
    s=input()
    n,r,ind,rs=len(s),0,0,[]
    l=[[0]*(n+1)]*(n+1)
    for i in range(1,n+1):
        for j in range(i+1,n+1):
            if s[i-1]==s[j-1] and l[i-1][j-1]<(j-i):
                l[i][j]=l[i-1][j-1]+1
                if l[i][j]>r:
                    r=l[i][j]
                    ind=max(i,ind)
            else:
                l[i][j]=0
    if r>0:
        j=0
        for i in range(ind-r+1,ind+1):
            rs.append(s[i-1])
    res=n-(2*len(rs))
    if n==res:
        print("No")
    else:
        print('Yes')
