#include <iostream>

int main() {
	int i = 0;
	unsigned char s[103];
	do {
		s[i] = getchar();
	} while (s[i++] != '\n');

	i = 0;
	while (s[i] != '\n') {
		if ('a' <= s[i] && 'z' >= s[i]) {
			s[i] += 13;
			if (s[i] > 'z') s[i] -= 26;
		}
		if ('A' <= s[i] && 'Z' >= s[i]) {
			s[i] += 13;
			if (s[i] > 'Z') s[i] -= 26;
		}
		printf("%c", s[i++]);
	}
	printf("\n");
}