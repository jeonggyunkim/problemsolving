#include <bits/stdc++.h>
using namespace std;

bool isv(char a) {
	if (a == 'a' || a == 'e' || a == 'o' || a == 'u' || a == 'i') return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (!isv(s[i]) && s[i] != 'n') {
			if (i == s.size() - 1 || !isv(s[i + 1])) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}