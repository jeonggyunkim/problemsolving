#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	int a, b, c;
	int d[3];
	cout.precision(30);
	while (tc--) {
		cin >> a >> b >> c;
		int time = 3600 * a + 60 * b + c;
		d[0] = time;
		d[1] = (time % 3600) * 12;
		d[2] = (time % 60) * 720;
		sort(d, d + 3);

		int ans = 987654321, now;
		now = d[2] - d[0];
		if (now > 21600) now = 43200 - now;
		ans = min(ans, now);

		now = d[1] - d[0];
		if (now > 21600) now = 43200 - now;
		ans = min(ans, now);

		now = d[2] - d[1];
		if (now > 21600) now = 43200 - now;
		ans = min(ans, now);

		cout << (double)ans / 120 << '\n';
	}
}