#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	while (cin >> a >> b, a || b) {
		char as[10], bs[10];
		for (int i = 9; i >= 0; --i) {
			as[i] = a % 10;
			a /= 10;
			bs[i] = b % 10;
			b /= 10;
		}
		int ans = 0;
		for (int i = 9; i >= 0; --i) {
			if (as[i] + bs[i] >= 10) {
				ans++;
				if (i) as[i - 1]++;
			}
		}
		cout << ans << '\n';
	}
}