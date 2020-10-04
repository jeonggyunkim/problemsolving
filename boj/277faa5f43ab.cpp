#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			cout << ' ';
		}
		cout << '*';
		for (int j = 0; j < 2 * i - 3; ++j) {
			cout << ' ';
		}
		if (i != 1) cout << '*';
		cout << '\n';
	}
	for (int i = 0; i < 2 * n - 1; ++i) {
		cout << '*';
	}
}