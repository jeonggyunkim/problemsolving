#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int sum[1025][1025];
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> sum[i][j];
			sum[i][j] += sum[i][j - 1];
			sum[i][j] += sum[i - 1][j];
			sum[i][j] -= sum[i - 1][j - 1];
		}
	}

	int a, b, c, d;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b >> c >> d;
		cout << sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1] << '\n';
	}
}