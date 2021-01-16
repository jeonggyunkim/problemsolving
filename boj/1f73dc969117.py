a, b = map(int, input().split())

c = a // b
d = a % b

if d < 0:
	d -= b
	c += 1

print(c)
print(d)