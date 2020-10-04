#include <iostream>
using namespace std;

int coin[23];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	char input[23];
	for (int i = 0; i < n; ++i) {
		cin >> input;
		for (int j = 0; j < n; ++j) {
			if (input[j] == 'H') coin[i] |= (1 << j);
		}
	}

	int ans = 987654321;
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) coin[j] = ~coin[j];
		}

		int loc = 0;
		for (int j = 1; j < (1 << n); j <<= 1) {
			int cnt = 0;
			for (int k = 0; k < n; ++k) {
				if (coin[k] & j) cnt++;
			}
			loc += min(cnt, n - cnt);
		}
		ans = min(loc, ans);

		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) coin[j] = ~coin[j];
		}
	}

	cout << ans;
}