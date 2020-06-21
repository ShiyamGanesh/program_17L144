def minop(l,n,k): 
    a=0
    for i in range(n):
        if l[i]!=1 and l[i]>k: 
            a+=min(l[i]%k,k-l[i]%k)
        else:
            a+=k-l[i] 
    return a
a=list(map(int,input().split()))
print(minop(a,len(a),int(input())))
