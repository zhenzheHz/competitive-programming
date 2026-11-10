# Author : zhenzhe
# 2026/10/31 Sat 21:36:51
import sys

def solve():
    s = [line.strip() for line in sys.stdin if line.strip()]
    if not s:
        return
    g = s[:5]
    lst = []
    for r in range(5):
        lst.append([(r, c) for c in range(5)])
    for c in range(5):
        lst.append([(r, c) for r in range(5)])
    lst.append([(i, i) for i in range(5)])
    lst.append([(i, 4 - i) for i in range(5)])
    ans = 5
    for l in lst:
        cnt = 0
        for r, c in l:
            if g[r][c] == '.':
                cnt += 1
        ans = min(ans, cnt)
    print(ans)

if __name__ == '__main__':
    solve()