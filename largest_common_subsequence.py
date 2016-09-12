
s1 = raw_input("Enter s1:").strip()
s2 = raw_input("Enter s2:").strip()

l1, l2 = len(s1)-1, len(s2)-1

def largest_common_subsequence(s1, l1, s2, l2, result):
	if l1 < 0 or l2 < 0:
		return 0
	if s1[0] == s2[0]:
		result.append(s1[0])
		return 1+largest_common_subsequence(s1[1:], l1-1, s2[1:], l2-1, result)
	else:
		result1 = []
		result2 = []
		lcs1 = largest_common_subsequence(s1[1:], l1-1, s2, l2, result1)
		lcs2 = largest_common_subsequence(s1, l1, s2[1:], l2-1, result2)
		if lcs1 > lcs2:
			for i in result1:
				result.append(i)
			return lcs1
		else:
			for i in result2:
				result.append(i)
			return lcs2

result = []
print largest_common_subsequence(s1, l1, s2, l2, result)
result_str = ''
for i in result:
	result_str += i
print result_str
