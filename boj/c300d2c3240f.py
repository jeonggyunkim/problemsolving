s = input()

cnt = s.count(':')
if cnt != 7:
	change = ':'
	for i in range(8 - cnt):
		change += '0:'
	s = s.replace('::', change)

if s[0] == ':':
	s = '0' + s
if s[-1] == ':':
	s = s + '0'

spt = s.split(':')
for i in range(len(spt)):
	if i:
		print(':', end = '')
	print(spt[i].zfill(4), end = '')