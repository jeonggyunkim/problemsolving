#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	long long t, ans = 0;
	for (int i = 0; i < n + m; ++i) cin >> t, ans += t;
	cout << ans;
}