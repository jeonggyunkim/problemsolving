#include <iostream>
using namespace std;

int main() {
	int T, n;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		cin >> n;
		for (int i = 0; i < 30; ++i) {
			if (n & (1 << i)) cout << i << ' ';
		}
		cout << endl;
	}
}