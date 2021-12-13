CFLAGS = -g -Wall -std=gnu++17
CFLAGS_FAST = -O2

make:
	g++ ${CFLAGS} -o a a.cpp
	./a < in
c:
	g++ ${CFLAGS} -o a a.cpp
	python3 coding_style_check.py
f:
	g++ ${CFLAGS_FAST} -o a a.cpp
	python3 coding_style_check.py
sec:
	g++ ${CFLAGS} -o a a.cpp main.cpp
	python3 coding_style_check.py
git:
	git add .
	git commit -m "$n"
	git push -u origin master
