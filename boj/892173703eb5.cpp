#include <iostream>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int mins = 1001, min = 1001, s, t;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &s, &t);
		if (s < mins) mins = s;
		if (t < min) min = t;
	}
	if (mins > 6 * min) printf("%d\n", n * min);
	else {
		if ((n % 6) * min > mins) printf("%d\n", (n / 6 + 1) * mins);
		else printf("%d\n", (n / 6) * mins + (n % 6) * min);
	}
}