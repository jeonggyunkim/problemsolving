#include <iostream>
#include <cmath>
using namespace std;

char arr[10][10];
int ans = -1;
int n, m;

bool isSq(int i) {
	int t = sqrt(i);
	if (t * t == i) return 1;
	else return 0;
}

void find(int i, int j, int ii, int jj) {
	int now = 0;
	while (i >= 0 && i < n && j >= 0 && j < m) {
		now *= 10;
		now += arr[i][j] - '0';
		if (isSq(now)) ans = max(ans, now);
		i += ii;
		j += jj;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	if (n == 1 && m == 1) {
		if (isSq(arr[0][0] - '0')) cout << arr[0][0];
		else cout << -1;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int ii = -n + 1; ii < n; ++ii) {
				for (int jj = -m + 1; jj < m; ++jj) {
					if (ii == 0 && jj == 0) continue;
					find(i, j, ii, jj);
				}
			}
		}
	}

	cout << ans;
}