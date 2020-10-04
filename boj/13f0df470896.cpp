#include <iostream>
#include <string>
using namespace std;

string s;

int cntz(int i) {
	int ret = 0;
	while (i < s.size() && s[i] == '0') {
		ret++;
		i++;
	}
	return ret;
}

int type1(int i) {
	if (i + 3 >= s.size() || s[i] != '1' || s[i + 1] != '0') return -1;
	int j = 2;
	int cnt = 0;
	while (i + j < s.size() && s[i + j] == '0') {
		cnt++;
		j++;
	}
	if (cnt == 0) return -1;
	cnt = 0;
	while (i + j < s.size() && s[i + j] == '1') {
		cnt++;
		j++;
	}
	if (cnt == 0) return -1;
	if (i + j == s.size()) return j;
	if (cntz(i + j) == 1) return j;
	else {
		if (cnt == 1) return -1;
		else return j - 1;
	}
}

bool type2(int i) {
	if (i + 1 >= s.size()) return 0;
	if (s[i] == '0' && s[i + 1] == '1') return 1;
	else return 0;
}

void solve() {
	int i = 0;
	while (i < s.size()) {
		if (s[i] == '0') {
			if (!type2(i)) {
				cout << "NO\n";
				return;
			}
			i += 2;
		}
		else {
			int r = type1(i);
			if (r == -1) {
				cout << "NO\n";
				return;
			}
			i += r;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s;
		solve();
	}
}