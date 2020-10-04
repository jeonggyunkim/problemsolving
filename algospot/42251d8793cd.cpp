#include <iostream>
#include <memory.h>

int n, cnt;
bool frd[11][11];
bool paired[11] = {0};

void pair(int s) {
	if (s == n) {
		cnt++;
		return;
	}
	if (paired[s] == 1) {
		pair(s + 1);
		return;
	}
	paired[s] = 1;
	for (int i = s + 1; i < n; ++i) {
		if (paired[i] == 0 && frd[s][i] == 1) {
			paired[i] = 1;
			pair(s + 1);
			paired[i] = 0;
		}
	}
	paired[s] = 0;
}


int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int m;
		scanf("%d %d", &n, &m);

		cnt = 0;
		memset(frd, 0, sizeof(frd));

		int a, b;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &a, &b);
			if (a > b) std::swap(a, b);
			frd[a][b] = 1;
		}
		pair(0);
		printf("%d\n", cnt);
	}
}
