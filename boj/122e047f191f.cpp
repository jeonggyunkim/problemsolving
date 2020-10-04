#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int n, m, cnt, ans;
int map[8][8], temp[8][8];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<ii> two;

void dfs(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m) return;
	if (temp[i][j] != 0) return;
	temp[i][j] = 2;
	cnt++;
	for (int k = 0; k < 4; ++k) {
		dfs(i + loc[k][0], j + loc[k][1]);
	}
}

void copy() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			temp[i][j] = map[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<ii> zero;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0) zero.push_back(ii(i, j));
			else if (map[i][j] == 2) {
				two.push_back(ii(i, j));
				map[i][j] = 0;
			}
		}
	}

	int z = zero.size();
	for (int i = 0; i < z; ++i) {
		for (int j = i + 1; j < z; ++j) {
			for (int k = j + 1; k < z; ++k) {
				copy();
				temp[zero[i].first][zero[i].second] = 1;
				temp[zero[j].first][zero[j].second] = 1;
				temp[zero[k].first][zero[k].second] = 1;

				cnt = -two.size();
				for (ii u: two) {
					dfs(u.first, u.second);
				}

				ans = max(ans, z - cnt - 3);
			}
		}
	}

	cout << ans;
}