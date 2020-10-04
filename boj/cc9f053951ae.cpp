#include <iostream>
using namespace std;

char pos[5000][625];
char neg[5000][625];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;

	char t;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> t;
		if (t == '+') {
			pos[i][j / 8] |= (1 << (j % 8));
		}
		else if (t == '-') {
			neg[i][j / 8] |= (1 << (j % 8));
		}
	}

	cin >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		if (pos[a][b / 8] & (1 << (b % 8))) cout << "+\n";
		if (neg[a][b / 8] & (1 << (b % 8))) cout << "-\n";
	}
}