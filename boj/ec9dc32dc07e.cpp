#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n >> m;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		sum += t + 1;
	}

	int i = 1;
	int ans = 0;
	while (sum < m) {
		int now = min(m - sum, n + 1);
		sum += now;
		ans += now * i * i;
		i++;
	}
	cout << ans;
}