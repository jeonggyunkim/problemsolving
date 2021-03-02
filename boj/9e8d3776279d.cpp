#include <iostream>
using namespace std;

int page[250][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	while (cin >> n, n) {
		cin >> p;
		int a = 1, b = n;
		for (int i = 0; i < n / 4; ++i) {
			page[i][0] = a++;
			page[i][1] = a++;
			page[i][3] = b--;
			page[i][2] = b--;
		}

		for (int i = 0; i < n / 4; ++i) {
			int exist = 0;
			for (int j = 0; j < 4; ++j) if (page[i][j] == p) exist = 1;
			if (exist) {
				for (int j = 0; j < 4; ++j) if (page[i][j] != p) cout << page[i][j] << ' ';
				cout << '\n';
			}
		}
	}
}