#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		if (k >= n - 1 - i) {
			cout << n - i << ' ';
			k -= n - 1 - i;
		}
		else {
			cout << 1 + k << ' ';
			for (int j = 0; j < n - i; ++j) {
				if (j + 1 != 1 + k) {
					cout << j + 1 << ' ';
				}
			}
			break;
		}
	}
}