#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	int sum[10001] = {};
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		sum[i] = sum[i - 1] + t;
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int j = i;
		while (j <= n) {
			t = sum[j] - sum[i - 1];
			if (t >= m) {
				if (t == m) cnt++;
				break;
			}
			++j;
		}
	}
	cout << cnt;
}