#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;

	bool can = false;
	for (int i = 0; i < s.size() - p; ++i) {
		if (s[i] == '.' || s[i + p] == '.') {
			if (s[i] == '.' && s[i + p] == '.') {
				s[i] = '0';
				s[i + p] = '1';
			}
			else if (s[i] == '.') s[i] = '0' + '1' - s[i + p];
			else s[i + p] = '0' + '1' - s[i];
			for (int j = 0; j < s.size(); ++j) {
				if (s[j] == '.') cout << '0';
				else cout << s[j];
			}
			return 0;
		}
		else if (s[i] != s[i + p]) {
			for (int j = 0; j < s.size(); ++j) {
				if (s[j] == '.') cout << '0';
				else cout << s[j];
			}
			return 0;
		}
	}
	cout << "No";
}