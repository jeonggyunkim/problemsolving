#include <iostream>
#include <set>
using namespace std;

int a, b;
int bo[5][5];
int cnt[5];
set<int> s;

bool endstate() {
	for (int i = 1; i <= 4; ++i) {
		if (bo[i][1] == bo[i][2] && bo[i][2] == bo[i][3] && bo[i][1]) {
			return 1;
		}
		if (bo[i][2] == bo[i][3] && bo[i][3] == bo[i][4] && bo[i][2]) {
			return 1;
		}
	}
	for (int i = 1; i <= 4; ++i) {
		if (bo[1][i] == bo[2][i] && bo[2][i] == bo[3][i] && bo[1][i]) {
			return 1;
		}
		if (bo[2][i] == bo[3][i] && bo[3][i] == bo[4][i] && bo[2][i]) {
			return 1;
		}
	}
	for (int i = 1; i <= 2; ++i) {
		for (int j = 1; j <= 2; ++j) {
			if (bo[i][j] == bo[i + 1][j + 1] && bo[i + 1][j + 1] == bo[i + 2][j + 2] && bo[i][j]) {
				return 1;
			}
		}
	}
	for (int i = 3; i <= 4; ++i) {
		for (int j = 1; j <= 2; ++j) {
			if (bo[i][j] == bo[i - 1][j + 1] && bo[i - 1][j + 1] == bo[i - 2][j + 2] && bo[i][j]) {
				return 1;
			}
		}
	}
	return 0;
}

void dfs(int turn) {
	if (bo[a][b]) {
		if (bo[a][b] == 1) return;
		if (endstate()) {
			int ret = 0;
			for (int i = 1; i <= 4; ++i) {
				for (int j = 1; j <= 4; ++j) {
					int num = 4 * (i - 1) + (j - 1);
					num *= 2;
					ret |= (bo[i][j] << num);
				}
			}
			s.insert(ret);
		}
		return;
	}
	if (endstate()) return;
	for (int i = 1; i <= 4; ++i) {
		if (cnt[i] != 4) {
			bo[cnt[i] + 1][i] = turn;
			cnt[i]++;
			dfs(3 - turn);
			cnt[i]--;
			bo[cnt[i] + 1][i] = 0;
		}
	}
}

int main() {
	int n;
	cin >> n >> a >> b;

	cnt[n]++;
	bo[1][n] = 1;
	dfs(2);

	cout << s.size();
}
