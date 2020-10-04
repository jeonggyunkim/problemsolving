MOD = [999999893, 999999929]

dic = {}

a1, a2 = 1, 1
b1, b2 = 1, 1
for i in range(2, 100010):
	dic[(b1, b2)] = i
	t1, t2 = b1, b2
	b1 = (a1 + b1) % MOD[0]
	b2 = (a2 + b2) % MOD[1]
	a1, a2 = t1, t2

n = int(input())

for i in range(n):
	t = int(input())
	print(dic[(t % MOD[0], t % MOD[1])])