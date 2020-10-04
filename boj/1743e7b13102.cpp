#include <iostream>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;

	if (l * (l - 1) / 2 > n) {
		cout << -1;
		return 0;
	}

	int sum;
	for (int i = l; i <= 100; ++i) {
		sum = (i - 1) * i / 2;
		if (sum > n) break;
		if ((n - sum) % i == 0) {
			int start = (n - sum) / i;
			for (int j = 0; j < i; ++j) cout << start + j << ' ';
			return 0;
		}
	}
	cout << -1;
}