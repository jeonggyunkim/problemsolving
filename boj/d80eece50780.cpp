#include <iostream>

int p[1000001];

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
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; ++i) p[i] = i;
	int t, a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &t, &a, &b);
		if (t) {
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else merge(a, b);
	}
	return 0;
}