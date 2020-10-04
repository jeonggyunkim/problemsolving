#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	char m = s[0];
	cout << "Mike\n";
	for (int i = 1; i < s.size(); ++i) {
		if (m < s[i]) cout << "Ann\n";
		else cout << "Mike\n";
		m = min(m, s[i]);
	}
}