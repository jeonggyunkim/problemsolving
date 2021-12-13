#include <iostream>
using namespace std;

int k;
string s;
string ans = "-1";

void rec(int ind, int d) {
	if (d == k || ind == s.size()) {
		if ((k - d) % 2 == 0 && ans < s) ans = s;
		return;
	}
	rec(ind + 1, d);
	for (int i = ind + 1; i < s.size(); ++i) {
		if (ind != 0 || s[i] != '0') {
			swap(s[ind], s[i]);
			rec(ind + 1, d + 1);
			swap(s[ind], s[i]);
		}
	}
}

int main() {
	cin >> s >> k;
	if ((s.size() == 1 && k) || (s.size() == 2 && s[1] == '0' && k)) cout << -1;
	else {
		rec(0, 0);
		cout << ans;
	}
}