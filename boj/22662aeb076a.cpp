#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef pair<int, int> ii;

ii base(string& a, string& b) {
	int ba = 0, st = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (a[i] == b[j]) ba++;
		}
		if (a[i] == b[i]) {
			ba--; st++;
		}
	}
	return ii(st, ba);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<string> s;
	for (char i = '1'; i <= '9'; ++i) {
		for (char j = '1'; j <= '9'; ++j) {
			if (i == j) continue;
			for (char k = '1'; k <= '9'; ++k) {
				if (i == k || j == k) continue;
				string str;
				str += i; str += j; str += k;
				s.insert(str);
			}
		}
	}

	int n;
	cin >> n;

	string str;
	int st, ba;
	for (int i = 0; i < n; ++i) {
		cin >> str >> st >> ba;
		set<string> news;
		for (string u: s) {
			ii t = base(u, str);
			if (t.first == st && t.second == ba) news.insert(u);
		}
		s = news;
	}

	cout << s.size();
}