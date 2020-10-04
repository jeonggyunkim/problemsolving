#include <iostream>
#include <memory.h>

char pal[2001][2001];
int num[2001];

int cal(int s, int e) {
	if (pal[s][e] != -1) return pal[s][e];
	if (e - s <= 0) return pal[s][e] = 1;
	if (num[s] == num[e]) return pal[s][e] = cal(s + 1, e - 1);
	else return pal[s][e] = 0;
}

int main() {
	int n, m, s, e;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", num + i);
	memset(pal, -1, sizeof(pal));

	scanf("%d", &m);
	while(m--) {
		scanf("%d %d", &s, &e);
		printf("%d\n", cal(s, e));
	}
}