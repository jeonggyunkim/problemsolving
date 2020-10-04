#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	map<string, string> m;
	m["purple"] = "Power";
	m["green"] = "Time";
	m["blue"] = "Space";
	m["orange"] = "Soul";
	m["red"] = "Reality";
	m["yellow"] = "Mind";

	string s;
	for (int i = 0; i < t; ++i) {
		cin >> s;
		m.erase(s);
	}

	cout << m.size() << '\n';
	for (auto it = m.begin(); it != m.end(); ++it) {
		cout << it->second << '\n';
	}
	return 0;
}