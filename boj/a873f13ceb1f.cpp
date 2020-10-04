#include <iostream>
using namespace std;

char mp[50][55];
int dist[9];

int main() {
	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; ++i) cin >> mp[i];

	for (int i = 0; i < r; ++i) {
		for (int j = c - 1; j >= 0; --j) {
			if (mp[i][j] >= '1' && mp[i][j] <= '9') {
				dist[mp[i][j] - '1'] = c - 1 - j;
			}
		}
	}

	int ans[9], cnt = 1;
	while (1) {
		int mini = 99;
		for (int i = 0; i < 9; ++i) {
			mini = min(mini, dist[i]);
		}
		if (mini == 99) break;
		for (int i = 0; i < 9; ++i) {
			if (dist[i] == mini) {
				ans[i] = cnt;
				dist[i] = 99;
			}
		}
		cnt++;
	}
	for (int i = 0; i < 9; ++i) cout << ans[i] << '\n';
}