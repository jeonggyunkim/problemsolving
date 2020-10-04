#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		switch (N) {
			case 1:
				cout << 1 << endl;
				break;
			case 2:
				cout << 2 << endl;
				break;
			case 3:
				cout << 4 << endl;
				break;
			default:
				int a = 1, b = 2, c = 4, d;
				for (int i = 0; i < N - 3; ++i) {
					d = a + b + c;
					a = b;
					b = c;
					c = d;
				}
				cout << c << endl;
				break;
		}

	}

	return 0;
}