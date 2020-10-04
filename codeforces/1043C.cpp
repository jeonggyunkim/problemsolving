#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] != s[i + 1]) cout << 1 << ' ';
		else cout << 0 << ' ';
	}

	if (s.back() == 'a') cout << 1;
	else cout << 0;
}