import random
import os

score = [480, 672, 954, 1374, 1992, 2909, 4276, 6329, 9430, 14145, 21288, 32145, 48699, 74023, 112885, 172714, 265117, 408280, 630792, 977727, 1520366, 2371771, 3711822, 5827560, 9178407, 14501883, 22985485, 36546921, 58292339, 93267742]

def select_index(arr):
    for i in range(len(arr)):
        if i:
            arr[i] += arr[i - 1]
    for i in range(len(arr)):
        arr[i] /= arr[-1]
    arr.append(2)
    r = random.random()
    ind = 0
    while r > arr[ind]:
        ind += 1
    return ind

def select_level():
    ret = []
    # bronze, silver
    bs = []
    for i in range(10):
        bs.append(score[i] ** (1 / 3))
    ret.append(select_index(bs) + 1)
    gd = []
    for i in range(10, 15):
        gd.append(1 / score[i] ** (1 / 3))
    ret.append(select_index(gd) + 11)
    pdr = []
    for i in range(15, 30):
        pdr.append(1 / score[i] ** (1 / 2))
    ret.append(select_index(pdr) + 16)

    return ret

solved = set()
dir = os.listdir('../boj')
for name in dir:
    solved.add(int(name[:name.find('.')]))
with open('boj_random.txt', 'rt') as f:
    a = f.read()
a = a.splitlines()
for name in a:
    solved.add(int(name))

goal = select_level()

with open('boj_tier_200802.txt', 'rt') as f:
    tier = f.read()
tier = tier.splitlines()
for i in range(len(tier)):
    tier[i] = tier[i].split()
    for j in range(len(tier[i])):
        tier[i][j] = int(tier[i][j])

real_arr = []
for num in tier[goal[2]]:
    if num not in solved:
        real_arr.append(num)
print('Challenge: https://www.acmicpc.net/problem/{}'.format(real_arr[random.randrange(len(real_arr))]))
real_arr = []
for num in tier[goal[1]]:
    if num not in solved:
        real_arr.append(num)
print('Moderate: https://www.acmicpc.net/problem/{}'.format(real_arr[random.randrange(len(real_arr))]))
real_arr = []
for num in tier[goal[0]]:
    if num not in solved:
        real_arr.append(num)
print('Easy: https://www.acmicpc.net/problem/{}'.format(real_arr[random.randrange(len(real_arr))]))
