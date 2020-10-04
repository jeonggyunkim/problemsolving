tc = int(input())

for test in range(tc):
	m, n = map(int, input().split())
	arr = [None for i in range(n)]
	dic = {}
	for i in range(n):
		arr[i] = list(map(int, input().split()))
	for i in range(m - 1, -1, -1):
		prod = 1
		for j in range(n):
			prod *= arr[j][i]
		dic[prod] = max(dic.get(prod, 0), i + 1)
	print(dic[max(dic)])