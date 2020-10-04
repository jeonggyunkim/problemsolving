#include <iostream>
#include <algorithm>
using namespace std;

int arr[22];
int quest[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, t;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> t;
			t--;
			quest[i] |= (1 << t);
		}
	}

	for (int i = n; i < 2 * n; ++i) arr[i] = 1;

	int ans = 0;
	do {
		int now = 0;
		for (int i = 0; i < 2 * n; ++i) {
			if (arr[i]) now |= (1 << i);
		}

		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			if ((now | quest[i]) == now) cnt++;
		}
		ans = max(ans, cnt);
	} while (next_permutation(arr, arr + 2 * n));

	cout << ans;
}