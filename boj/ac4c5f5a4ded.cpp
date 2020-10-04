#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans, t;
	cin >> ans;
	for (int i = 0; i < 9; ++i) {
		cin >> t;
		ans -= t;
	}
	cout << ans;
}