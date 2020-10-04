#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	if (n == 1) cout << "YES\n0";
	else if (n == 2) {
		if (a == 2 && b == 1) cout << "YES\n00\n00";
		else if (a == 1 && b == 2) cout << "YES\n01\n10";
		else cout << "NO";
	}
	else if (n == 3) {
		if (a == 3 && b == 1) cout << "YES\n000\n000\n000";
		else if (a == 2 && b == 1) cout << "YES\n010\n100\n000";
		else if (a == 1) {
			if (b == 2) cout << "YES\n011\n100\n100";
			else if (b == 3) cout << "YES\n011\n101\n110";
			else cout << "NO";
		}
		else cout << "NO";
	}
	else {
		if (a > 1 && b > 1) cout << "NO";
		else if (a == 1 && b == 1) {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (j == i + 1 || j == i - 1) cout << '1';
					else cout << '0';
				}
				cout << '\n';
			}
		}
		else {
			cout << "YES\n";
			bool matrix[1000][1000] = {};
			for (int i = 0; i < n - max(a, b); ++i) matrix[i][i + 1] = matrix[i + 1][i] = 1;
			if (a != 1) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) cout << matrix[i][j];
					cout << '\n';
				}
			}
			else {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						if (i == j) cout << 0;
						else cout << !matrix[i][j];
					}
					cout << '\n';
				}
			}
		}
	}
}