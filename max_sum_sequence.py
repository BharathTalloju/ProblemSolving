#!/bin/python
from sys import maxint

def find_max_c_sequence(l , n):
    max_sum = l[0]
    for i in l:
        if i >= 0:
            if i > max_sum:
                max_sum = 0
            max_sum += i
    return max_sum

def find_max_sequence(l, n):
    prev_max_sum = -maxint
    max_sum = -maxint
    right_array = [0]*n

    for i in xrange(n-2, -1, -1):
        if right_array[i+1] > 0:
            right_array[i] = right_array[i+1] + l[i+1]
        else:
            right_array[i] = l[i+1]
    print right_array

    for i in xrange(n):
        max_sum = l[i]
        for j in xrange(i+1, n):
            if l[j] + right_array[j] > 0:
                max_sum += l[j]
            else:
                if max_sum > prev_max_sum:
                    prev_max_sum = max_sum

    return max(prev_max_sum, max_sum)

T = int(raw_input().strip())
for t in xrange(T):
    n = int(raw_input().strip())
    l = map(int, raw_input().strip().split())
    print find_max_sequence(l, n), find_max_c_sequence(l, n)
