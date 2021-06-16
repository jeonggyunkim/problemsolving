make:
	g++ -Wall -std=gnu++17 -g -o a a.cpp
	./a < in
r:
	./a < in
c:
	g++ -g -Wall -std=gnu++17 -g -o a a.cpp
d:
	gdb a
git:
	git add .
	git commit -m "$n"
	git push -u origin master
