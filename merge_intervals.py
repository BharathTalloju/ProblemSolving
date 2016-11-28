n = int(raw_input().strip())
intervals = []
result = []
for i in xrange(n):
	interval = map(int, raw_input().strip().split())
	intervals.append(interval)
print intervals
intervals = sorted(intervals, key=lambda x : x[0])
print intervals
i = 0
while i+1 < len(intervals):
	if intervals[i][1] >= intervals[i+1][0]:
		intervals[i][1] = intervals[i+1][1]
		intervals.pop(i+1)
		continue
	i+=1
print intervals
