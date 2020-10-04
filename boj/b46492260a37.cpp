#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) cout << '*';
		else cout << " *";
		for (int j = 0; j < n - 1; ++j) {
			cout << " *";
		}
		cout << '\n';
	}
}