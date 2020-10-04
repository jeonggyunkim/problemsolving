#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		cout << n * (n + 1) / 2 << ' ';
		cout << n * n << ' ';
		cout << n * (n + 1) << '\n';
	}
}