inp = []
n, k = map(int, input().split())
base = n ** 10

if n == 1:
    for i in range(11):
        print(0)
    exit(0)

dic = [{} for i in range(11)]

for i in range(k):
    inp.append(list(map(int, input().split())))
    for j in range(11):
        key = []
        for k in range(1, 11):
            key.append(inp[i][(j + k) % 11])
        key = tuple(key)
        if key not in dic[j]:
            dic[j][key] = []
        dic[j][key].append(inp[i][j])

for i in range(11):
    ans = 0
    for j in dic[i].keys():
        ans -= 1
        l = dic[i][j]
        l.append(0)
        l.append(n + 1)
        l.sort()
        for j in range(len(l) - 1):
            if l[j + 1] - l[j] >= 3:
                ans += 1
    print(base + ans)