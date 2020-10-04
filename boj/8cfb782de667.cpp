#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[101][101], b[101][101], c[101][101] = {};
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	cin >> m >> k;
	for (int i = 0; i < m; ++i) for (int j = 0; j < k; ++j) cin >> b[i][j];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			for (int t = 0; t < m; ++t) c[i][j] += a[i][t] * b[t][j];
			cout << c[i][j] << ' ';
		}
		cout << '\n';
	}
}