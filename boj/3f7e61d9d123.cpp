#include <iostream>
using namespace std;

int main() {
	int x, n;
	cin >> x >> n;

	if (n == 0) {
		if (x <= 0) cout << 0;
		else cout << "INFINITE";
	}
	else if (n == 1) {
		if (x >= 0) cout << 0;
		else cout << "INFINITE";
	}
	else if (n & 1) {
		cout << "ERROR";
	}
	else {
		n /= 2;
		if (x - n <= 0) cout << 0;
		else {
			cout << (x - n - 1) / n + 1;
		}
	}
}