with open('a.cpp', 'rt') as f:
    code = f.read()

if code.find('    ') != -1:
    print('indent error')
if code.find(' \n') != -1:
    print('useless space after code')
if code.find('\t\n') != -1:
    print('useless tab after code')
if code.find('\n\n\n') != -1:
    print('double newline')