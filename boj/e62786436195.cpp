#include <iostream>

int main() {
	int s = 0, n, t;
	char ope[7];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", ope);
		if (ope[0] == 'e') s = 0;
		else if (ope[1] == 'l') s = (1 << 21) - 1;
		else {
			scanf("%d", &t);
			if (ope[0] == 'a') s |= (1 << t);
			else if (ope[0] == 'r') s &= ~(1 << t);
			else if (ope[0] == 'c') printf("%d\n", (bool)((1 << t) & s));
			else if (ope[0] == 't') s ^= (1 << t);
		}
	}
}