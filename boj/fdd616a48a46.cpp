#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int t[9][9];
int mask[9][9];
ii list[72];
bool used[72];

inline bool can_put(int i, int j, int n) {
	return mask[i][j] & (1 << n);
}

ii next_pos(ii pos) {
	int i = pos.first, j = pos.second;
	while (j < 9) {
		if (t[i][j]) j++;
		else return ii(i, j);
		if (j == 9) {
			i++;
			j = 0;
		}
	}
}

void add_elem(int i, int j, int n) {
	t[i][j] = n;

	mask[i][j] = 0;
	for (int p = 0; p < 9; ++p) {
		mask[i][p] &= ~(1 << n);
		mask[p][j] &= ~(1 << n);
	}
	int x = i / 3 * 3, y = j / 3 * 3;
	for (int p = 0; p < 3; ++p) for (int q = 0; q < 3; ++q) mask[x + p][y + q] &= ~(1 << n);
}

int put(ii pos) {
	int i = pos.first, j = pos.second;
	if (i >= 9) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) cout << t[i][j];
			cout << '\n';
		}
		return 1;
	}
	int tt[9][9], mt[9][9];
	memcpy(tt, t, sizeof(t));
	memcpy(mt, mask, sizeof(mask));

	if (j != 8 && t[i][j + 1] == 0) {
		for (int k = 0; k < 72; ++k) {
			if (used[k]) continue;
			if (can_put(i, j, list[k].first) && can_put(i, j + 1, list[k].second)) {
				used[k] = 1;
				add_elem(i, j, list[k].first);
				add_elem(i, j + 1, list[k].second);
				if (put(next_pos(pos))) return 1;
				memcpy(t, tt, sizeof(t));
				memcpy(mask, mt, sizeof(mask));
				used[k] = 0;
			}
			if (can_put(i, j, list[k].second) && can_put(i, j + 1, list[k].first)) {
				used[k] = 1;
				add_elem(i, j, list[k].second);
				add_elem(i, j + 1, list[k].first);
				if (put(next_pos(pos))) return 1;
				memcpy(t, tt, sizeof(t));
				memcpy(mask, mt, sizeof(mask));
				used[k] = 0;
			}
		}
	}
	if (i != 8 && t[i + 1][j] == 0) {
		for (int k = 0; k < 72; ++k) {
			if (used[k]) continue;
			if (can_put(i, j, list[k].first) && can_put(i + 1, j, list[k].second)) {
				used[k] = 1;
				add_elem(i, j, list[k].first);
				add_elem(i + 1, j, list[k].second);
				if (put(next_pos(pos))) return 1;
				memcpy(t, tt, sizeof(t));
				memcpy(mask, mt, sizeof(mask));
				used[k] = 0;
			}
			if (can_put(i, j, list[k].second) && can_put(i + 1, j, list[k].first)) {
				used[k] = 1;
				add_elem(i, j, list[k].second);
				add_elem(i + 1, j, list[k].first);
				if (put(next_pos(pos))) return 1;
				memcpy(t, tt, sizeof(t));
				memcpy(mask, mt, sizeof(mask));
				used[k] = 0;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t1, t2, num = 1;
	char s[3];
	while (cin >> n, n) {
		cout << "Puzzle " << num++ << '\n';
		memset(t, 0, sizeof(t));
		for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) mask[i][j] = (1 << 10) - 2;
		memset(used, 0, sizeof(used));
		int check[10][10] = {};
		for (int i = 0; i < n; ++i) {
			cin >> t1 >> s;
			add_elem(s[0] - 'A', s[1] - '1', t1);
			cin >> t2 >> s;
			add_elem(s[0] - 'A', s[1] - '1', t2);
			if (t1 > t2) swap(t1, t2);
			check[t1][t2] = 1;
		}

		for (int i = 1; i <= 9; ++i) {
			cin >> s;
			add_elem(s[0] - 'A', s[1] - '1', i);
		}

		int cnt = 0;
		for (int i = 1; i <= 9; ++i) for (int j = i + 1; j <= 9; ++j) {
			if (check[i][j]) used[cnt++] = 1;
			else list[cnt++] = ii(i, j);
		}
		put(next_pos(ii(0, 0)));
	}
}