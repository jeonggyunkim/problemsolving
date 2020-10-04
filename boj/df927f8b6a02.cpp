#include <iostream>
using namespace std;

char input[101][101];
char output[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> input[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char& t = input[i][j];
			if (t == 'O') t = 'O';
			else if (t == '-') t = '|';
			else if (t == '|') t = '-';
			else if (t == '/') t = '\\';
			else if (t == '\\') t = '/';
			else if (t == '^') t = '<';
			else if (t == '<') t = 'v';
			else if (t == 'v') t = '>';
			else if (t == '>') t = '^';
			output[m - 1 - j][i] = input[i][j];
		}
	}

	for (int i = 0; i < m; ++i) cout << output[i] << '\n';
}