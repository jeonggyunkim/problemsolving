#include <iostream>
using namespace std;

bool sim(int* a, int* b) {
	int s = 0, first = -1;
	for (int i = 0; i < 26; ++i) {
		if (a[i] != b[i]) {
			if (first == -1) first = i;
			if (a[i] - b[i] > 1 || a[i] - b[i] < -1) return false;
			else {
				++s;
				if (s == 2) if ((a[first] + a[i]) != (b[first] + b[i])) return false;
				if (s >= 3) return false;
			}
		}
	}
	return true;
}

int main() {
	int n, i, count = 0;
	char ori[15];
	char buf[15];
	int c1[26] = {};

	scanf("%d", &n);
	scanf("%s", ori);
	i = 0;
	while (ori[i]) ++c1[ori[i++] - 'A'];
	for (int j = 1; j < n; ++j) {
		scanf("%s", buf);
		int c2[26] = {};
		i = 0;
		while (buf[i]) ++c2[buf[i++] - 'A'];
		if (sim(c1, c2)) count++;
	}

	printf("%d\n", count);
	return 0;
}