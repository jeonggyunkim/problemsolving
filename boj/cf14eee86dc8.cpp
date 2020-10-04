#include <iostream>
using namespace std;

int box[1001][1001];
bool mask[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
		cin >> box[i][j];
	}

	for (int i = 0; i < m; ++i) {
		int max = -1, maxi;
		for (int j = 0; j < n; ++j) {
			if (box[i][j] > max) {
				max = box[i][j];
				maxi = j;
			}
		}
		mask[i][maxi] = 1;
	}

	for (int j = 0; j < n; ++j) {
		int max = -1, maxi;
		for (int i = 0; i < m; ++i) {
			if (box[i][j] > max) {
				max = box[i][j];
				maxi = i;
			}
		}
		mask[maxi][j] = 1;
	}

	long long ans = 0;
	for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
		if (!mask[i][j]) ans += box[i][j];
	}

	cout << ans;
}