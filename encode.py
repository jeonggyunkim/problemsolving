import sys
import hashlib

argc = len(sys.argv)

if argc == 1:
    print('usage: num')
    sys.exit(0)

with open('key.txt', 'rt') as f:
    key = f.read()

num = sys.argv[1]

m = hashlib.sha256()
num = key + num
m.update(num.encode())
encrypt = m.hexdigest()[:12]

print(encrypt)