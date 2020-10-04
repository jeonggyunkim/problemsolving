#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = -1;
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, (i + 1) * (n - i + 1));
	}
	cout << ans;
}