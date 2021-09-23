import os

for i in range(100):
	os.system("python3 make_data.py > in")
	os.system("./a < in > mout")
#	os.system("./b < in > out")
#	a = os.system("diff mout out")
#	if a:
#		break
	print(i, "/100", end = '\r')
