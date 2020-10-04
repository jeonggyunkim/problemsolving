#include <iostream>

bool is_a(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	char buf[22];

	while (scanf("%s", buf), (buf[0] != 'e' || buf[1] != 'n' || buf[2] != 'd' || buf[3] != 0)) {
		bool a = false;
		int a_seq = 0;
		int b_seq = 0;
		int i = 0;
		bool brk = true;
		while (buf[i] != 0) {
			if (is_a(buf[i])) {
				a = true;
				a_seq += 1;
				b_seq = 0;
			}
			else {
				b_seq += 1;
				a_seq = 0;
			}
			if (a_seq >= 3 || b_seq >= 3) {
				printf("<%s> is not acceptable.\n", buf);
				brk = false;
				break;
			}
			if (buf[i] == buf[i + 1] && buf[i] != 'e' && buf[i] != 'o') {
				printf("<%s> is not acceptable.\n", buf);
				brk = false;
				break;
			}
			i++;
		}
		if (brk) {
			if (a) printf("<%s> is acceptable.\n", buf);
			else printf("<%s> is not acceptable.\n", buf);
		}
	}
}