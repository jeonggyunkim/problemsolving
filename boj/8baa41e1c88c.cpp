#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	int x = 0;
	for (int i = 1; i <= n; ++i) x ^= i;

	for (int i = 1; i < n; ++i) {
		cin >> t;
		x ^= t;
	}
	cout << x;
}