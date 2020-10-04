#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	int a;
	bool b = false;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < x) {
			if (b) {
				cout << ' ';
			}
			b = true;
			cout << a;
		}
	}

	return 0;
}