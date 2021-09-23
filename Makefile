CFLAGS = -g -Wall -std=gnu++17
CFLAGS_FAST = -O2

make:
	g++ ${CFLAGS} -o a a.cpp
	./a < in
r:
	./a < in
c:
	g++ ${CFLAGS} -o a a.cpp
f:
	g++ ${CFLAGS_FAST} -o a a.cpp
d:
	gdb a
sec:
	g++ ${CFLAGS} -o a a.cpp main.cpp
git:
	git add .
	git commit -m "$n"
	git push -u origin master
