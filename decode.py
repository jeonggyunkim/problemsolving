import sys
import hashlib

argc = len(sys.argv)

if argc == 1:
    print('usage: name')
    sys.exit(0)

with open('key.txt', 'rt') as f:
    key = f.read()

name = sys.argv[1]

for num in range(1000, 100000):
	m = hashlib.sha256()
	m.update((key + str(num)).encode())
	encrypt = m.hexdigest()[:12]
	if encrypt == name:
		print(num)
		break
