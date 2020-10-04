#include <iostream>

int main() {
	int low, upp, num, spa;
	char cc;
	while (true) {
		low = upp = num = spa = 0;
		cc = 0;
		while (cc != '\n' && cc != EOF) {
			cc = getchar();
			if (cc == ' ') spa++;
			else if ('0' <= cc && '9' >= cc) num++;
			else if ('a' <= cc && 'z' >= cc) low++;
			else if ('A' <= cc && 'Z' >= cc) upp++;
		}
		if (cc == EOF) break;
		printf("%d %d %d %d\n", low, upp, num, spa);
	}
}