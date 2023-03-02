#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < q; ++i) {
		if (i & 1) cout << n << '\n';
		else cout << n - 1 << '\n';
	}
}