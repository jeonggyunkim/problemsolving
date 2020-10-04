#include <iostream>

int tree[10001];

void walk(int s, int f) {
	if (f - s <= 1) {
		if (f - s == 1) printf("%d\n", tree[s]);
		return;
	}

	int root = tree[s];
	int n = s + 1;
	while (n < f && tree[n] < root) n++;
	walk(s + 1, n);
	walk(n, f);
	printf("%d\n", root);
}

int main() {
	int t, i = 0;
	while (scanf("%d", &t) == 1) tree[i++] = t;

	walk(0, i);
}