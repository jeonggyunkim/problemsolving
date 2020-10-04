#include <iostream>
using namespace std;

int ans[101];

int main() {
	ans[0] = 1;
	int p = 3;

	for (int i = 0; i < 100; i += 2) {
		ans[i + 1] = ans[i] + p / 3;
		ans[i + 2] = ans[i] + p;
		p *= 2;
	}

	int n;
	cin >> n;
	n -= 2;

	for (int i = 0; i <= 100; ++i) {
		if (n - 1 < ans[i]) {
			cout << i << '\n';
			break;
		}
	}
}