import sys

argc = len(sys.argv)

if argc == 1:
    print('usage: num des lang')
    sys.exit(0)

if (argc >= 4):
    lang = sys.argv[3]
else:
    lang = 'cpp'

if (argc >= 3):
    des = sys.argv[2]
else:
    des = 'boj'

num = sys.argv[1]

with open('a.{}'.format(lang), 'rt') as f:
    code = f.read()

b = 1
try:
    with open('{}/{}.{}'.format(des, num, lang), 'rt') as f:
        pass
    print('The file already exist. Do you want to replace it?')
    if input() != 'y':
        b = 0
except:
    pass

if b:
    with open('{}/{}.{}'.format(des, num, lang), 'wt') as f:
        f.write(code)
