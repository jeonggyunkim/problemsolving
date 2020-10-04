prime = [1 for i in range(8001)]
prime[0] = prime[1] = 0
i = 2
while i * i <= 8000:
    if prime[i]:
        j = i * i
        while j <= 8000:
            prime[j] = 0
            j += i
    i += 1

ans = 1
for i in range(8001):
    if prime[i]:
        ans *= i

while True:
    n, t = input().split()
    if n == '0':
        break
    print(ans - 1, end = '')
    for i in range(int(n) - 3421):
        print('9', end = '')
    print()
