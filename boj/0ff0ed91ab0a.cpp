#include <iostream>

int pos[5] = {0, 4, 8, 14, 20};

int main() {
	int cnt = 0;
	while (true) {
		int c = getchar();
		if (c == '\n') {
			printf("%d\n", cnt);
			cnt = 0;
			continue;
		}
		if (c == '#') break;
		for (int i = 0; i < 5; ++i) {
			if (c == pos[i] + 'a' || c == pos[i] + 'A') cnt++;
		}
	}
}