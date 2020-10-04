#include <iostream>

int main() {
	int d10, d12, d16, j;
	for (int i = 1000; i < 10000; ++i) {
		d10 = d12 = d16 = 0;
		j = i;
		while (j) {
			d10 += j % 10;
			j /= 10;
		}
		j = i;
		while (j) {
			d12 += j % 12;
			j /= 12;
		}
		if (d10 == d12) {
			j = i;
			while (j) {
				d16 += j % 16;
				j /= 16;
			}
			if (d12 == d16) printf("%d\n", i);
		}
	}
}