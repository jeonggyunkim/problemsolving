#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int m = n;
	int cnt = 0;
	while (m) {
		cnt += 9;
		m /= 10;
	}
	for (int i = max(1, n - cnt); i < n; ++i) {
		int j = i, k = i;
		while (j) {
			k += j % 10;
			j /= 10;
		}
		if (k == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}