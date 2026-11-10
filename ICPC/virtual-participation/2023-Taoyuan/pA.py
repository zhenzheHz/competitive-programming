# Author : ysh
# 2026/10/15 Thu 14:58:14
for _ in range(int(input())):
    n = input()[::-1]
    f = []
    for i in range(0, len(n), 3):
        f.append(n[i:i + 3][::-1])

    f = [int(i) for i in f]
    for i in range(len(f)):
        if i & 1:
            f[i] = -f[i]

    ans = abs(sum(f))
    print(ans, 'YES' if ans % 13 == 0 else 'NO')

quit()
