#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	if (t == 1) {
		for (int i = 2; i <= 8; ++i) {
			cin >> t;
			if (t != i) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "ascending";
	}
	else if (t == 8) {
		for (int i = 7; i >= 1; --i) {
			cin >> t;
			if (t != i) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "descending";
	}
	else {
		cout << "mixed";
	}
}