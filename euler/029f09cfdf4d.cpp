#include <iostream>
using namespace std;

int main() {
	int large = -1, ans;
	for (int p = 12; p <= 1000; ++p) {
		int cnt = 0;
		for (int a = 1; a < p / 3; ++a) {
			for (int b = a + 1; b < (p - a) / 2; ++b) {
				int c = p - a - b;
				if (a * a + b * b == c * c) cnt++;
			}
		}
		if (cnt > large) {
			large = cnt;
			ans = p;
		}
	}
	cout << ans << endl;
}