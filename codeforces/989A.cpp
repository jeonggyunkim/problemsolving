#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size() - 1; ++i) {
		bool a[3] = {};
		for (int j = -1; j <= 1; ++j) if (s[i + j] != '.') a[s[i + j] - 'A'] = 1;
		if (a[0] && a[1] && a[2]) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}