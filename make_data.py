import random

print(1)
n = 1000
k = 10000
print(n, k)
s = ''
for j in range(n):
	s += chr(ord('a') + random.randrange(26))
print(s)

for i in range(k):
	s = ''
	for j in range(3):
		s += chr(ord('a') + random.randrange(26))
	print(s)
