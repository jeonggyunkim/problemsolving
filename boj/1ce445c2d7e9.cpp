#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		string a, b;
		cin >> a >> b;

		int a1 = 0, b1 = 0;

		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) {
				if (a[i] == '1') a1++;
				else b1++;
			}
		}

		cout << abs(a1 - b1) + min(a1, b1) << '\n';
	}
}