#include <iostream>
#include <string>
using namespace std;

bool ans[2000][2000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'B') ans[i][j] = 1;
		}
	}

	if (n == 1) {
		if (m != 1) {
			ans[0][0] = !ans[0][0];
			ans[0][m - 1] = !ans[0][m - 1];
		}
	}
	else if (m == 1) {
		ans[0][0] = !ans[0][0];
		ans[n - 1][0] = !ans[n - 1][0];
	}
	else {
		for (int j = 1; j < m - 1; ++j) ans[0][j] = !ans[0][j];
		for (int j = 1; j < m - 1; ++j) ans[n - 1][j] = !ans[n - 1][j];
		for (int j = 1; j < n - 1; ++j) ans[j][0] = !ans[j][0];
		for (int j = 1; j < n - 1; ++j) ans[j][m - 1] = !ans[j][m - 1];
	}

	cout << "1\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ans[i][j]) cout << "3";
			else cout << "2";
		}
		cout << '\n';
	}
}