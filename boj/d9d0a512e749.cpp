#include <iostream>
using namespace std;

int d[2][4] = { {1, 2, -1, 2}, {2, -1, 2, 1} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cout << "YES\n";
	if (n % 4 != 3) {
		int now = 1;
		for (int i = 0; i < n; ++i) {
			cout << now << ' ';
			now += d[0][i % 4];
		}
	}
	else {
		int now = 1;
		for (int i = 0; i < n; ++i) {
			cout << now << ' ';
			now += d[1][i % 4];
		}
	}
}