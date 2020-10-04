#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 2 * n; ++i) {
		int j = 0;
		if (i % 2 == 0) {
			cout << '*';
			++j;
		}
		for (; j < n - 1; j += 2) {
			cout << " *";
		}
		cout << '\n';
	}
}