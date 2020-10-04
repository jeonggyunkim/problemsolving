#include <iostream>

int t[3];

void f(char* p, int a, int n) {
	int i = 0;
	while (i < 3) {
		if (p[a % n] != '-') {
			t[i] = a;
			++i;
		}
		++a;
	}
}

int s(char* p, int n) {
	t[0] = 0; t[1] = 0; t[2] = 0;
	int j = 0;
	bool b = true;
	int v = 1;
	int h = 1;
	while (v + h && j < n) {
		f(p, j, n);
		if (p[t[0] % n] == 'L' && p[t[1] % n] == 'R' && p[t[2] % n] == 'R') {
			if (b) {
				v = 0;
			} else {
				h = 0;
			}
			p[t[0] % n] = 'R';
			p[t[1] % n] = '-';
			p[t[2] % n] = '-';
			int c = 2;
			while (j > 0 && c) {
				j--;
				if (p[j % n] != '-') {
					b = !b;
					c--;
				}
			}
			continue;
		}
		j = t[1];
		b = !b;
	}
	return v + h;
}

int main() {
	int n;
	scanf("%d", &n);

	char p[100001];
	for (int i = 0; i < n; i++) {
		scanf("%s", p);
		int j = 0;
		while (p[j] != '\0') ++j;
		printf("%d\n", s(p, j));
	}
}