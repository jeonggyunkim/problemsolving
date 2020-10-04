#include <iostream>
using namespace std;

int time() {
	int h, m, s;
	scanf("%d:%d:%d", &h, &m, &s);
	return 3600 * h + 60 * m + s;
}

int main() {
	int t1, t2;
	t1 = time();
	t2 = time();
	if (t2 <= t1) t2 += 86400;

	int t = t2 - t1;
	printf("%02d:", t / 3600);
	t %= 3600;
	printf("%02d:", t / 60);
	t %= 60;
	printf("%02d", t);
}