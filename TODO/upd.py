import requests
from bs4 import BeautifulSoup as bs
import json
import os
import hashlib

with open('../key.txt', 'rt') as f:
    key = f.read()

boj = set()
boj_list = os.listdir('../boj')
for i in boj_list:
    name = i[:i.find('.')]
    if name in boj:
        print("Douplicated file:", name)
    boj.add(name)

with open('boj_random.txt', 'rt') as f:
    boj_random = f.read().splitlines()

rand = set()
for i in boj_random:
    rand.add(i)

r = requests.get('https://www.acmicpc.net/user/sslktong')
soup = bs(r.text, features="html.parser")
div = soup.findAll('div', attrs={'class':'panel panel-default'})[0]
span = div.findAll('a')
for i in range(len(span)):
    num = span[i].text
    m = hashlib.sha256()
    m.update((key + num).encode())
    encrypt = m.hexdigest()[:12]
    if encrypt in boj:
        boj.remove(encrypt)
    elif num in rand:
        rand.remove(num)
    else:
        print('file number', num, 'does not exist', '(https://www.acmicpc.net/problem/{})'.format(num))

for num in boj:
    print('Something wrong.. {}'.format(num))
    print('Trying to find number: ', end = '')
    for n in range(1000, 100000):
        m = hashlib.sha256()
        m.update((key + str(n)).encode())
        encrypt = m.hexdigest()[:12]
        if num == encrypt:
            print('https://www.acmicpc.net/problem/{})'.format(n))
            break

for num in rand:
    print('Something wrong in random.. {}'.format(num))
print('BOJ clear!')
