#!/bin/python
#N = int(raw_input().strip())
N = 234
dp = [-1]*(N+1)
dp[1] = 0
for i in xrange(2,N+1):
    dp[i] = 1 + dp[i-1]
    if i%2 == 0:
        dp[i] = min(dp[i], 1+dp[i/2])
        pass
    if i%3 == 0:
        dp[i] = min(dp[i], 1+dp[i/3])
        pass
print dp[N]
