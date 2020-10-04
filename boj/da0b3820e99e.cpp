#include <iostream>

int main() {
	int n;
	scanf("%d ", &n);

	while (n--) {
		bool first = 1;
		while (true) {
			char t = getchar();
			if (first) {
				if (t >= 'a' && t <= 'z') printf("%c", t - 'a' + 'A');
				else printf("%c", t);
			}
			if (t == EOF) break;
			if (!first) printf("%c", t);
			else first = 0;
			if (t == '\n') break;
		}
	}
}