#!/bin/python
memo = [-1]*(235)
memo[1] = 0
def get_min_steps(n):
    if n == 1:
        return 0
    if memo[n] != -1:
        return memo[n]
    r = 1 + get_min_steps(n-1)
    if n%2 == 0:
        r = min(r, 1+get_min_steps(n/2))
        pass
    if n%3 == 0:
        r = min(r, 1+get_min_steps(n/3))
        pass
    memo[n] = r
    #print "memo[",n,"]=",r
    return r

print get_min_steps(234)
