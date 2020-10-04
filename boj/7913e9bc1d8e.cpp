#include <iostream>

int p[300010];

int find(int n) {
	if (n == p[n]) return n;
	if (p[n] == -1) return -1;
	return p[n] = find(p[n]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == -1 && b == -1) return false;
	if (a == -1 || b == -1) a == -1 ? p[b] = -1 : p[a] = -1;
	else if (a != b) p[a] = b;
	else p[a] = -1;
	return true;
}

int main() {
	int N, L;

	scanf("%d %d", &N, &L);
	for (int i = 1; i <= L; ++i) p[i] = i;
	int a, b;
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &a, &b);
		if (merge(a, b)) printf("LADICA\n");
		else printf("SMECE\n");
	}
}