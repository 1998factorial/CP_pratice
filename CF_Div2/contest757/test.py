a = [7,7,7,0,2]
ans = 0
for i in range(0,len(a)):
    for j in range(i,len(a)):
        v = 0
        for k in range(i,j+1):
            v=v^a[k]
        ans = ans + v
print(ans)