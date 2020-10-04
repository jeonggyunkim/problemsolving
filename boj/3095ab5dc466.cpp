#include <iostream>
using namespace std;

int main() {
	int r, c, a, b;
	cin >> r >> c >> a >> b;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < a; ++j) {
			for (int k = 0; k < c; ++k) {
				for (int l = 0; l < b; ++l) {
					if ((i + k) % 2 == 0) cout << 'X';
					else cout << '.';
				}
			}
			cout << '\n';
		}
	}
}
