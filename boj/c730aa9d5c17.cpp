#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int t;
	for (int i = 0; i < n; ++i) {
		bool pos = 1;
		for (int j = 0; j < 10; ++j) {
			cin >> t;
			if (t != j % 5 + 1) {
				pos = 0;
			}
		}
		if (pos) cout << i + 1 << '\n';
	}
}