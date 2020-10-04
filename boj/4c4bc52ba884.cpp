#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		t--;
		if (t == i) {
			cout << -1;
			return 0;
		}
	}
	cout << 1000000007;
}