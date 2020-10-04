#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int r, g, b;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> r >> g >> b;
			int i = 2126 * r + 7152 * g + 722 * b;
			if (i < 510000) cout << '#';
			else if (i < 1020000) cout << 'o';
			else if (i < 1530000) cout << '+';
			else if (i < 2040000) cout << '-';
			else cout << '.';
		}
		cout << '\n';
	}
}