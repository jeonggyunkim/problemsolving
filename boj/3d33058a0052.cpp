#include <iostream>
#include <string>
using namespace std;

int n;
string s;

bool empty(int i) {
	for (int j = 0; j < 5; ++j) {
		if (s[i + j * n] == '#') return 0;
	}
	return 1;
}

int to_num(int i, int j) {
	if (j - i == 1) return 1;
	if (s[i + 1] == '.') return 4;
	if (s[i + 2 * n] == '.') return 7;
	if (s[i + 2 * n + 1] == '.') return 0;
	if (s[i + n] == '.') {
		if (s[i + 3 * n] == '.') return 3;
		else return 2;
	}
	if (s[i + n + 2] == '.') {
		if (s[i + 3 * n] == '.') return 5;
		else return 6;
	}
	if (s[i + 3 * n] == '.') return 9;
	return 8;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	n /= 5;

	int i = 0;
	while (i < n) {
		if (empty(i)) i++;
		else {
			int j = i + 1;
			while (j < n && !empty(j)) j++;
			cout << to_num(i, j);
			i = j;
		}
	}
}