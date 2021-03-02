#include <iostream>
using namespace std;

long long ans[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 1000000; ++i) {
		ans[i] = ans[i - 1] + (2 * i - 1);
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int a, b;
		cin >> a >> b;
		cout << ans[a / b] << '\n';
	}
}