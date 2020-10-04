#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += i * (i + 1) * 3 / 2;
	}
	cout << ans;
}