#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

bool change[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		vector<int> arr(n);
		for (int i = 0; i < n; ++i) cin >> arr[i];

		memset(change, 0, sizeof(change));

		int m;
		cin >> m;

		int a, b;
		while (m--) {
			cin >> a >> b;
			change[a][b] = 1;
			change[b][a] = 1;
		}

		vector<int> win(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (change[arr[i]][arr[j]]) win[arr[j]]++;
				else win[arr[i]]++;
			}
		}

		vector<int> cnt(n, -1);
		bool incon = 0;
		for (int i = 1; i <= n; ++i) {
			if (cnt[win[i]] != -1) {
				cout << "IMPOSSIBLE\n";
				incon = 1;
				break;
			}
			cnt[win[i]] = i;
		}

		if (!incon) {
			for (int i = n - 1; i >= 0; --i) cout << cnt[i] << ' ';
			cout << '\n';
		}
	}
}