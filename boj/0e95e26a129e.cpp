#include "game.h"
#include <memory.h>
#include <algorithm>

int cnt[1500][1500];
int N;

int build(int l, int r, int a, int b) {
	if (r - l == 3) {
		cnt[l][r]++;
		if (cnt[l][r] == 1) return 1;
		else if (cnt[l][r] == 2) return 0;
		else return 1;
	}
	if (r - l == 2) {
		return 1;
	}
	int mid = (l + r) / 2;
	bool b1 = a < mid;
	bool b2 = b < mid;
	if (b1 == b2) {
		if (b1) return build(l, mid, a, b);
		else return build(mid, r, a, b);
	}
	else {
		cnt[l][r]++;
		if (cnt[l][r] == (r - mid) * (mid - l)) return 1;
		else return 0;
	}
}

void initialize(int n) {
	N = n;
	memset(cnt, 0, sizeof(cnt));
}

int hasEdge(int u, int v) {
	if (u > v) std::swap(u, v);
	return build(0, N, u, v);
}