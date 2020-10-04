#include <iostream>

int p[100005];

int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	p[b] = a;
}

int main() {
	int G, P, t;
	scanf("%d %d", &G, &P);
	for (int i = 0; i <= G; ++i) p[i] = i;

	for (int i = 0; i < P; ++i) {
		scanf("%d", &t);
		t = find(t);
		if (t == 0) {
			printf("%d", i);
			return 0;
		}
		merge(t - 1, t);
	}
	printf("%d", P);
}