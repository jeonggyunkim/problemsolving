#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = -1, t;
	while (n--) {
		cin >> t;
		ans = max(ans, t);
	}

	cout << ans;
}