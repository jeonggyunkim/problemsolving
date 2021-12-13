import sys

argc = len(sys.argv)

if argc != 2:
    print('usage: num')
    sys.exit(0)

num = sys.argv[1]
des = '../sw'
lang = 'cpp'

with open('a.{}'.format(lang), 'rt') as f:
    code = f.read()

if code.find('    ') != -1:
    print('indent error')
if code.find(' \n') != -1:
    print('useless space after code')
if code.find('\t\n') != -1:
    print('useless tab after code')
if code.find('\n\n\n') != -1:
    print('double newline')

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