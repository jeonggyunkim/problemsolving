#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int c = 100;
	int s = 100;

	for (int i = 0; i < n; ++i) {
		int tc, ts;

		cin >> tc >> ts;

		if (tc > ts) {
			s -= tc;
		}
		else if(tc < ts) {
			c -= ts;
		}
	}
	cout << c << endl;
	cout << s << endl;

	return 0;
}