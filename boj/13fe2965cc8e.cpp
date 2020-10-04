#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	char map[50][51];
	for (int i = 0; i < n; ++i) cin >> map[i];

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == '#') {
				if (i & 1) {
					if (i > 0) {
						if (map[i - 1][j] == '.') ans++;
						if (j < m - 1 && map[i - 1][j + 1] == '.') ans++;
					}
					if (i < n - 1) {
						if (map[i + 1][j] == '.') ans++;
						if (j < m - 1 && map[i + 1][j + 1] == '.') ans++;
					}
				}
				else {
					if (i > 0) {
						if (j > 0 && map[i - 1][j - 1] == '.') ans++;
						if (map[i - 1][j] == '.') ans++;
					}
					if (i < n - 1) {
						if (j > 0 && map[i + 1][j - 1] == '.') ans++;
						if (map[i + 1][j] == '.') ans++;
					}
				}
				if (j > 0 && map[i][j - 1] == '.') ans++;
				if (j < m - 1 && map[i][j + 1] == '.') ans++;
			}
		}
	}
	cout << ans;
}