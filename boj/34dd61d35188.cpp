#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		char gogi[12][12];
		int h, w;
		cin >> h >> w;

		for (int i = 0; i < h; ++i) cin >> gogi[i];
		for (int i = h - 1; i >= 0; --i) {
			cout << gogi[i];
			cout << '\n';
		}
	}
}