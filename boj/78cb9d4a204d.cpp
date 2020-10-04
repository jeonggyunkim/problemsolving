#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t, r = 0;
	cin >> n;

	for (int i = 1; i < n; ++i) r ^= i;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		r ^= t;
	}

	cout << r;
}