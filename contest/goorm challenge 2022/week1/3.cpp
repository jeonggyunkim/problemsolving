#include <iostream>
using namespace std;

int main() {
	int t[4], ans = -1;
	cin >> t[0] >> t[1] >> t[2] >> t[3];

	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (k != i && k != j) {
					ans = max(ans, abs(t[i] - t[j]) + abs(t[k] - t[6 - i - j - k]));
					break;
				}
			}
		}
	}
	cout << ans;
}