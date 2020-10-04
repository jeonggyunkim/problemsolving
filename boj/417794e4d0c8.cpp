#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		int sum = (r1 + r2) * (r1 + r2);
		int dif = (r1 - r2) * (r1 - r2);

		if (d == 0) {
			if (dif == 0) cout << -1;
			else cout << 0;
		}
		else if (d == sum || d == dif) cout << 1;
		else if (dif < d && d < sum) cout << 2;
		else cout << 0;
	}
}