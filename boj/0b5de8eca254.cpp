#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> arr[10];
	int t, tt;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		while (t--) {
			cin >> tt;
			tt--;
			arr[i].push_back(tt);
		}
	}

	int ans = 11;

	for (int i = 0; i < (1 << m); ++i) {
		int mask = 0;
		for (int j = 0; j < m; ++j) {
			if (i & (1 << j)) {
				for (int u: arr[j]) mask |= (1 << u);
			}
		}
		if (mask == ((1 << n) - 1)) ans = min(ans, __builtin_popcount(i));
	}

	if (ans == 11) cout << -1;
	else cout << ans;
}