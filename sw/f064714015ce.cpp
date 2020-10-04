#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int p, q, r, s, w;
		cin >> p >> q >> r >> s >> w;

		cout << '#' << test << ' ' << min(p * w, q + max(w - r, 0) * s) << '\n';
	}
}