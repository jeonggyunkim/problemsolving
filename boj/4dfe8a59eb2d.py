from collections import deque

def find(n):
	global dp
	if n <= 1024:
		return dp[n]
	
	ret = 2 ** 60
	for p in range(2, 61):
		low = 1
		high = int((2 ** 60) ** (1 / p)) + 1
		while high - low != 1:
			mid = (high + low) // 2
			value = 1
			for i in range(p):
				value *= mid
			if n < value:
				high = mid
			else:
				low = mid
		
		value = 1
		for i in range(p):
			value *= low
		ret = min(ret, find(low) + 1 + abs(value - n))

		value = 1
		for i in range(p):
			value *= high
		ret = min(ret, find(high) + 1 + abs(value - n))
	return ret

dp = [-1 for i in range(1025)]

n = int(input())

q = deque()
dp[1] = 0
q.append(1)

while q:
	now = q.popleft()
	next = now + 1
	if next >= 1 and next <= 1024:
		if dp[next] == -1:
			dp[next] = dp[now] + 1
			q.append(next)

	next = now - 1
	if next >= 1 and next <= 1024:
		if dp[next] == -1:
			dp[next] = dp[now] + 1
			q.append(next)

	if now == 1:
		continue

	next = now * now
	while next <= 1024:
		if dp[next] == -1:
			dp[next] = dp[now] + 1
			q.append(next)
		next *= now

print(find(n))