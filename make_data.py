import random

n = 10
q = 10

f = open("in", "wt")

print(n, q, file = f)
for i in range(n):
	print(random.randrange(100), end = ' ', file = f)
print(file = f)

for i in range(q):
	op = random.randrange(3)
	l = random.randrange(n)
	r = random.randrange(n)
	if r < l:
		r, l = l, r

	if op == 0:
		print(0, l, r, random.randrange(1, 1001), file = f)
	elif op == 1:
		print(1, l, r, random.randrange(1, 1001), file = f)
	else:
		print(2, l, r, random.randrange(1, 1001), file = f)

f.close()