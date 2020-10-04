#include <iostream>
using namespace std;

bool digit(int n) {
	int cnt[10] = {};
	int m = n;
	while (n) {
		cnt[n % 10]++;
		n /= 10;
	}
	for (int i = 2 * m; i <= 6 * m; i += m) {
		int now[10] = {};
		int t = i;
		while (t) {
			now[t % 10]++;
			t /= 10;
		}
		for (int j = 0; j < 10; ++j) {
			if (cnt[j] != now[j]) return 0;
		}
	}
	return 1;
}

int main() {
	for (int i = 1; ; ++i) {
		if (digit(i)) {
			cout << i << endl;
			return 0;
		}
	}
}