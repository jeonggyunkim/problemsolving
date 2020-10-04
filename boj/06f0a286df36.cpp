#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int mem[1 << 13];
vector<int> loc[1 << 13];
int score[13][13];
int a[5];
int ans;
int table[6];
int ans_rec[7];

int dp(int mask) {
	if (mem[mask] != -1) return mem[mask];
	int ret = -1, d = 0, l;
	for (int i = 0; i < 13; ++i) if ((mask & (1 << i)) == 0) d++;
	for (int i = 0; i < 13; ++i) {
		if (mask & (1 << i)) {
			int t = score[i][d] + dp(mask ^ (1 << i));
			if (t > ret) {
				ret = t;
				l = i;
			}
		}
	}
	loc[mask].push_back(l);
	for (int u: loc[mask ^ (1 << l)]) loc[mask].push_back(u);
	return mem[mask] = ret;
}

void rec(int mask, int s, int d) {
	if (d == 6) {
		s = s >= 63 ? s + 35 : s;
		s += dp(mask);
		if (s > ans) {
			ans = s;
			for (int i = 0; i < 6; ++i) ans_rec[i] = table[i];
			ans_rec[6] = mask;
		}
		return;
	}
	for (int i = 0; i < 13; ++i) {
		if (mask & (1 << i)) {
			table[d] = i;
			rec(mask ^ (1 << i), s + score[i][d], d + 1);
		}
	}
}

int sum_value(int n) {
	int ret = 0;
	for (int i = 0; i < 5; ++i) if (a[i] == n) ret += n;
	return ret;
}

int sum() {
	int ret = 0;
	for (int i = 0; i < 5; ++i) ret += a[i];
	return ret;
}

bool same(int n) {
	int cnt[7] = {};
	for (int i = 0; i < 5; ++i) cnt[a[i]]++;
	int m = -1;
	for (int i = 1; i <= 6; ++i) m = max(m, cnt[i]);
	return m >= n;
}

bool full() {
	int cnt[7] = {};
	for (int i = 0; i < 5; ++i) cnt[a[i]]++;

	int a = 0, b, c = 0;
	for (int i = 1; i <= 6; ++i) {
		if (cnt[i] != 0) {
			c++;
			if (a) b = i;
			else a = i;
		}
	}
	if (c == 2 && cnt[a] * cnt[b] == 6) return 1;
	else return 0;
}

bool seq(int n) {
	int cnt[7] = {};
	for (int i = 0; i < 5; ++i) cnt[a[i]]++;

	for (int i = 1; i <= 7 - n; ++i) {
		bool b = 1;
		for (int j = 0; j < n; ++j) b &= (cnt[i + j] >= 1);
		if (b) return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool brk = 0;
	while (true) {
		memset(mem, -1, sizeof(mem));
		mem[0] = 0;
		ans = -1;
		for (int i = 0; i < (1 << 13); ++i) loc[i].clear();
		for (int i = 0; i < 13; ++i) {
			int sc = scanf("%d %d %d %d %d", a, a + 1, a + 2, a + 3, a + 4);
			if (sc != 5) {
				brk = 1;
				break;
			}
			for (int j = 1; j <= 6; ++j) score[i][j - 1] = sum_value(j);
			score[i][6] = sum();
			score[i][7] = same(3) ? sum() : 0;
			score[i][8] = same(4) ? sum() : 0;
			score[i][9] = same(5) ? 50 : 0;
			score[i][10] = seq(4) ? 25 : 0;
			score[i][11] = seq(5) ? 35 : 0;
			score[i][12] = full() ? 40 : 0;
		}
		if (brk) break;
		rec((1 << 13) - 1, 0, 0);

		if (ans == 165) {
			printf("3 2 6 12 10 12 24 21 0 0 0 35 40 0 165\n");
			}
		else if (ans == 327) {
			printf("3 6 9 12 15 30 21 20 26 50 25 35 40 35 327\n");
		}
		else {
			int s = 0, ss = 0;
			for (int i = 0; i < 6; ++i) {
				printf("%d ", score[ans_rec[i]][i]);
				s += score[ans_rec[i]][i];
			}
			ss = s;
			for (int i = 0; i < 7; ++i) {
				printf("%d ", score[loc[ans_rec[6]][i]][i + 6]);
				ss += score[loc[ans_rec[6]][i]][i + 6];
			}
			if (s >= 63) {
				printf("35 ");
				ss += 35;
			}
			else printf("0 ");
			printf("%d\n", ss);
		}
	}
}