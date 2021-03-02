#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, c;
		cin >> n >> c;
		cout << (n + c - 1) / c << '\n';
	}
}