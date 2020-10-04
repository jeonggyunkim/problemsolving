#include <iostream>

int p[202];

int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[b] = a;
}

int main() {
	int n, m, t;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) p[i] = i;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &t);
			if (j > i && t) merge(i, j);
		}
	}
	int a, b;
	scanf("%d", &b);
	for (int j = 1; j < m; ++j) {
		a = b;
		scanf("%d", &b);
		if (find(a - 1) != find(b - 1)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}