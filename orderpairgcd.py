from itertools import combinations as c
l=[i for i in range(1,int(input())+1)]*2
a=[]
for i in set(c(l,2)):
    if sorted(list(i)) not in a and max(i)%min(i)==0:
        a.append(sorted(list(i)))
print(len(a))
