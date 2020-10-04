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
    boj.add(i[:i.find('.')])

with open('boj_random.txt', 'rt') as f:
    boj_random = f.read().splitlines()

rand = set()
for i in boj_random:
    rand.add(i)

r = requests.get('https://www.acmicpc.net/user/sslktong')
soup = bs(r.text, features="html.parser")
div = soup.findAll('div', attrs={'class':'panel panel-default'})[0]
span = div.findAll('span', attrs={'class':'problem_number'})
for i in range(len(span)):
    num = span[i].text
    m = hashlib.sha256()
    m.update((key + num).encode())
    encrypt = m.hexdigest()[:12]
    if encrypt not in boj and num not in rand:
        print('file number', num, 'does not exist')
print('BOJ clear!')
