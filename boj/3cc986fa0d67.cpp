#include <iostream>
using namespace std;

int main() {
	long long t;
	cin >> t;

	for (int n = 3; ; ++n) {
		long long sum = 0;
		for (int s = 1; ; ++s) {
			long long now = 1;
			for (int i = 0; i < n - 1; ++i) now *= s;
			sum += now;
			if (sum == t) {
				cout << n << ' ' << s;
				return 0;
			}
			else if (sum > t) {
				if (s == 2) {
					cout << "impossible";
					return 0;
				}
				break;
			}
		}
	}
}