import os
import time

time_limit = 2.0

input_files = os.listdir('input')
output_files = os.listdir('output')

pair = []

for i in input_files:
    for j in output_files:
        if i[:i.find('in')] == j[:j.find('out')]:
            pair.append((i, j))
            
os.system("g++ -o a a.cpp")
outstr = ''
for i, o in pair:
    start = time.time()
    os.system("./a < input/{} > mout".format(i))
    end = time.time()
    
    out = os.system("diff -b output/{} mout".format(o))
    t = end - start
    
    if t > time_limit:
        outstr += 'Time Limit Exceeded on case {}\n'.format(i)
    elif out != 0:
        outstr += 'Wrong answer on case {}\n'.format(i)
    else:
        outstr += '{} accepted\n'.format(i)

print(outstr)
