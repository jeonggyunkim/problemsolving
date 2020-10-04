#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int a[4], b[4];
		for (int i = 0; i < 4; ++i) cin >> a[i];
		for (int i = 0; i < 4; ++i) {
			cin >> b[i];
			a[i] += b[i];
		}
		if (a[0] < 1) a[0] = 1;
		if (a[1] < 1) a[1] = 1;
		if (a[2] < 0) a[2] = 0;

		cout << a[0] + 5 * a[1] + 2 * (a[2] + a[3]) << '\n';
	}
}