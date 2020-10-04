#include <iostream>
using namespace std;

bool arr[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t & 1) arr[i] = 1;
	}

	int ans = 0, mini = 987654321;
	bool even = 1;
	for (int i = 0; i < k; ++i) {
		int one = 0, zero = 0;
		for (int j = i; j < n; j += k) {
			if (arr[j]) one++;
			else zero++;
		}
		if (one > zero) even = !even;
		ans += min(one, zero);
		mini = min(mini, abs(one - zero));
	}
	if (!even) ans += mini;
	cout << ans;
}