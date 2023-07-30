#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	int mx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		mx = max(mx, t - (n - i));
	}
	cout << mx;
}