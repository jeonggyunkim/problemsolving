#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, p, l;
		cin >> n >> p >> l;

		for (int i = p; i < l + p; ++i) {
			if (i % 3 == 0) {
				int j = i / 3;
				while (j % 2 == 0) j /= 2;
				if (j % 4 == 3) cout << '-';
				else cout << '+';
			}
			else {
				if (i % 6 > 3) {
					if (i % 3 == 1) cout << 'Y';
					else cout << 'F';
				}
				else {
					if (i % 3 == 1) cout << 'F';
					else cout << 'X';
				}
			}
		}
		cout << '\n';
	}
}
