#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, ans = 0;
	cin >> n >> k;

	int a, b;
	while (k--) {
		cin >> a >> b;
		a--; b--;
		ans++;
		if (a != 0) ans++;
		if (a != n - 1) ans++;
		if (b != 0) ans++;
		if (b != n - 1) ans++;
	}
	cout << ans;
}