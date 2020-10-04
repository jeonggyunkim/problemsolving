#include <bits/stdc++.h>
using namespace std;

int start(int n, int k) {
	return (k <= 30) ? (n - 1) / ((1 << k) - 1) + 1 : 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, k;
	cin >> n >> k;

	for (int a = start(n, k); ; a++) {
		long long mini;
		mini = (2 * a + k - 1) * k / 2;
		if (mini > n) {
			cout << "NO";
			break;
		}

		vector<int> ans(k);
		ans[0] = a;
		n -= a;

		for (int i = 1; i < k; ++i) {
			ans[i] = max(ans[i - 1] + 1, start(n, k - i));
			n -= ans[i];
		}

		cout << "YES\n";
		for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
		break;
	}
}
