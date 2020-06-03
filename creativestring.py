from functools import reduce
from collections import Counter as c
t,n=map(int,input().split())
l=[]
for _ in range(t):
    s=input()
    l.append([ord(i) for i in list(s)])
'''print(l)
q=[item for item,count in c(l).items() if count>1]
print(q)
for i in range(len(q)):
    l=list(filter((q[i]).__ne__,l))
print(l)'''
res=list(reduce(lambda i,j:i^j,(set(x) for x in l)))
print(chr(min(res)))


    
