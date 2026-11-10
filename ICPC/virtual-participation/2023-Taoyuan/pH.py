C = int(input())

v = [int(i) for i in input().split()]
w = [int(i) for i in input().split()]

N = len(v)

v = [0] + v
w = [0] + w

dp = [[0 for _ in range(C+1)] for i in range(N+1)]

for i in range(1,N+1):
    for j in range(1,C+1):
        if w[i] > j: 
            dp[i][j] = dp[i-1][j]
            # print(len(dp[i]))
            continue
        dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i-1][j])

print(dp[N][C])
