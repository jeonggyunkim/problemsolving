from decimal import *

def SQ(t):
	low, high = 0, int(t ** 0.5 + 10)
	while high - low != 1:
		mid = (low + high) // 2
		if mid * mid <= t:
			low = mid
		else:
			high = mid
	if low * low == t:
		return low
	else:
		return -1

def conv(a):
	for i in range(len(a)):
		if a[i] == '.':
			ret = int(a[:i]) * 10 ** 11
			if a[0] == '-':
				ret -= int(a[i + 1:]) * 10 ** (12 - len(a) + i)
			else:
				ret += int(a[i + 1:]) * 10 ** (12 - len(a) + i)
			return ret
	return int(a) * 10 ** 11

getcontext().prec = 30

tc = int(input())

for test in range(tc):
	a, b, c, d = map(conv, input().split())
	ans = 0

	if d != 0:
		i = 1
		while i * i <= abs(d):
			if d % i == 0:
				for j in [i, -i, abs(d) // i, -abs(d) // i]:
					if a * j * j * j + b * j * j + c * j + d == 0:
						ans = j
						break
				if ans:
					break
			i += 1

	aa = a
	bb = a * ans + b
	cc = a * ans * ans + b * ans + c

	D = bb * bb - 4 * aa * cc
	if D > 0:
		anss = []
		anss.append(Decimal(ans))
		S = SQ(D)
		if S != -1:
			down = Decimal(2 * aa)
			up = Decimal(-bb + S)
			if up % down != 0 or up // down != ans:
				anss.append(up / down)
			up = Decimal(-bb - S)
			if up % down != 0 or up // down != ans:
				anss.append(up / down)
		else:
			D = Decimal(D).sqrt()
			ans2 = Decimal(-bb)

			anss.append((ans2 + D) / (2 * aa))
			anss.append((ans2 - D) / (2 * aa))
		anss.sort()
		for i in anss:
			print(i, end = ' ')
		print()
	elif D == 0:
		if -bb % (2 * aa) == 0 and -bb // (2 * aa) == ans:
			print(ans)
		else:
			ans = Decimal(ans)
			ans2 = Decimal(-bb)
			ans2 /= Decimal(2 * aa)
			print(min(ans, ans2), max(ans, ans2))
	else:
		print(ans)