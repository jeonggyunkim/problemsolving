#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n >> m;

	vector<int> arr(n + 1, 0);
	while (m--) {
		cin >> t;
		for (int i = t; i <= n; i += t) arr[i] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) if (arr[i]) ans += i;

	cout << ans;
}