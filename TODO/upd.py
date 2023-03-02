import requests
from bs4 import BeautifulSoup as bs
import json
import os
import hashlib

with open('../key.txt', 'rt') as f:
    key = f.read()

duplicated = set() # hash
rand = set()
with open('boj_extra.txt', 'rt') as f:
    cnt = 0
    for line in f.readlines():
        line = line.strip()
        try:
            int(line)
            line = line.strip()
            if cnt == 1:
                m = hashlib.sha256()
                m.update((key + line).encode())
                encrypt = m.hexdigest()[:12]
                duplicated.add(encrypt)
            else:
                rand.add(line)
        except:
            if line:
                cnt += 1

boj = set()
boj_list = os.listdir('../boj')
for i in boj_list:
    name = i[:i.find('.')]
    if name in boj:
        if name in duplicated:
            duplicated.remove(name)
        else:
            print("Duplicated file:", name)
    boj.add(name)

headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Safari/537.36'}
r = requests.get('https://www.acmicpc.net/user/sslktong', headers = headers)
soup = bs(r.text, features="html.parser")
for rep in [0, 3]:
    div = soup.findAll('div', attrs={'class':'problem-list'})[rep]
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

for num in boj.union(duplicated).union(rand):
    print('Something wrong.. {}'.format(num))
    if num in duplicated:
        print('It must be duplicated file')
    print('Trying to find number: ', end = '')
    for n in range(100000):
        m = hashlib.sha256()
        m.update((key + str(n)).encode())
        encrypt = m.hexdigest()[:12]
        if num == encrypt:
            print('https://www.acmicpc.net/problem/{}'.format(n), end = '')
            break
    print()

print('BOJ clear!')