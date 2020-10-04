#include <iostream>
using namespace std;

int p[201][201];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	while (m--) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		p[a][b] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n - 2; ++i) {
		for (int j = i + 1; j <= n - 1; ++j) {
			for (int k = j + 1; k <= n; ++k) {
				if (!p[i][j] && !p[i][k] && !p[j][k]) ans++;
			}
		}
	}
	cout << ans;
}