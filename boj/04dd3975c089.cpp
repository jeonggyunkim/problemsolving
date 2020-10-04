#include <iostream>
#define min(a, b) (a < b ? a : b)

int a, b, c;
bool t[201][201][201] = {0};
bool poss[201] = {0};

void dfs(int na, int nb, int nc) {
	if (t[na][nb][nc] == 1) return;
	t[na][nb][nc] = 1;
	if (na == 0) poss[nc] = 1;
	int m;
	if (na) {
		m = min(na, b - nb);
		dfs(na - m, nb + m, nc);
		m = min(na, c - nc);
		dfs(na - m, nb, nc + m);
	}
	if (nb) {
		m = min(nb, a - na);
		dfs(na + m, nb - m, nc);
		m = min(nb, c - nc);
		dfs(na, nb - m, nc + m);
	}
	if (nc) {
		m = min(nc, a - na);
		dfs(na + m, nb, nc - m);
		m = min(nc, b - nb);
		dfs(na, nb + m, nc - m);
	}
}

int main() {
	scanf("%d %d %d", &a, &b, &c);
	dfs(0, 0, c);
	for (int i = 0; i <= 200; ++i) if (poss[i]) printf("%d ", i);
}