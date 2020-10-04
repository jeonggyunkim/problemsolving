#include <iostream>

int main() {
	int e, s, m, me = 1, ms = 1, mm = 1;
	scanf("%d %d %d", &e, &s, &m);

	int y = 1;
	while (true) {
		if (e == me && s == ms && m == mm) break;
		y++; me++; ms++; mm++;
		if (me > 15) me -= 15;
		if (ms > 28) ms -= 28;
		if (mm > 19) mm -= 19;
	}
	printf("%d\n", y);
}