#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int p[50], s[50], t[50], tt[50];
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		t[i] = p[i];
	}
	for (int i = 0; i < n; ++i) cin >> s[i];

	for (int test = 0; ; ++test) {
		bool b = 0;
		for (int i = 0; i < n; ++i) {
			if (t[i] != (i % 3)) {
				b = 1;
				break;
			}
		}
		if (!b) {
			cout << test;
			return 0;
		}
		for (int i = 0; i < n; ++i) tt[s[i]] = t[i];
		for (int i = 0; i < n; ++i) t[i] = tt[i];
		b = 0;
		for (int i = 0; i < n; ++i) {
			if (t[i] != p[i]) {
				b = 1;
				break;
			}
		}
		if (!b) {
			cout << -1;
			return 0;
		}
	}
}