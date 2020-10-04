#include <iostream>
using namespace std;

long long arr[51];

bool can(int a, int b) {
	if (a > b) swap(a, b);
	for (int i = a + 1; i < b; ++i) {
		if (arr[i] * (b - a) >= (b - i) * arr[a] + (i - a) * arr[b]) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int look = 0;
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (can(i, j)) look++;
		}
		ans = max(ans, look);
	}

	cout << ans;
}