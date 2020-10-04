import random

data = '''5 3 2 8 7 6 4 1 9 
1 6 4 2 3 9 5 7 8 
8 7 9 4 1 5 2 6 3 
2 1 6 7 9 3 8 4 5 
4 8 3 1 5 2 7 9 6 
9 5 7 6 4 8 3 2 1 
6 4 5 3 2 1 9 8 7 
3 2 1 9 8 7 6 5 4 
7 9 8 5 6 4 1 3 2'''

data = data.splitlines()
for i in range(len(data)):
	data[i] = data[i].split()

import copy
import time
import os

while 1:
	now = copy.deepcopy(data)
	num = random.randrange(40, 82)

	st = set()
	for i in range(9):
		for j in range(9):
			st.add((i, j))

	for i in range(num):
		i = random.choice(list(st))
		now[i[0]][i[1]] = '0'
		st.discard(i)

	f = open('in', 'wt')
	for i in range(9):
		for j in range(9):
			print(now[i][j], end = ' ', file = f)
		print(file = f)
	f.close()

#	start = time.time()
#	os.system("./a < in")
#	end = time.time()
#	t1 = end - start

	start = time.time()
	os.system("./b < in")
	end = time.time()
	t2 = end - start

	if t2 > 0.5:
		print(t2)
		for i in range(9):
			for j in range(9):
				print(now[i][j], end = ' ')
			print()
		break