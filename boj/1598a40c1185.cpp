#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int con1[6] = {500, 300, 200, 50, 30, 10};
	int con2[5] = {512, 256, 128, 64, 32};

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;

		int ans = 0;
		if (a == 0 || a > 21) ans += 0;
		else {
			int i = 1;
			while (a > 0) {
				a -= i;
				i++;
			}
			ans += con1[i - 2];
		}

		if (b == 0 || b > 31) ans += 0;
		else {
			int i = 1, j = 1;
			while (b > 0) {
				b -= i;
				i *= 2;
				j++;
			}
			ans += con2[j - 2];
		}

		cout << ans * 10000 << '\n';
	}
}