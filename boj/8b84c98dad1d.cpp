#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, t;
	cin >> n >> k;

	vector<int> pos;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t == 1) pos.push_back(i);
	}

	if (pos.size() < k) {
		cout << -1;
		return 0;
	}

	int ans = n;
	for (int i = 0; i <= pos.size() - k; ++i) {
		ans = min(ans, pos[i + k - 1] - pos[i] + 1);
	}
	cout << ans;
}