#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	if (s.size() % 2 == 0) {
		cout << s.size() / 2;
	}
	else {
		int ans = (s.size() - 1) / 2;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] != '0') {
				ans++;
				break;
			}
		}
		cout << ans;
	}
}