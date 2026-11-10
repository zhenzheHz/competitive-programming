n,q = map(int, input().split())
f = [i+1 for i in range(n)]
kk = list(map(int, input().split()))

for j in range(q):
    k = kk[j]
    a = [-f[i] for i in range(k)]
    b = [f[i] for i in range(k, n)]
    f = list(reversed(a)) + b
    # print(f)

for i in range(n):
    print(f[i])