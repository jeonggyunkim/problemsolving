#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		string str;
		cin >> str;

		set<ii> s[2];
		if (str[0] != '{') {
			cout << "Word #" << test << ": No Set\n";
			continue;
		}
		s[0].insert({1, 1});
		for (int i = 1; i < str.size(); ++i) {
			set<ii>* cur = &s[i % 2];
			for (ii now: s[(i + 1) % 2]) {
				if (now.second <= 0) continue;
				if (now.first == 1) {
					if (str[i] == '{') {
						cur->insert({1, now.second + 1});
						cur->insert({4, now.second});
					}
					else if (str[i] == '}') {
						cur->insert({2, now.second - 1});
						cur->insert({4, now.second});
					}
					else cur->insert({4, now.second});
				}
				else if (now.first == 2) {
					if (str[i] == '{') continue;
					else if (str[i] == '}') {
						cur->insert({2, now.second - 1});
					}
					else cur->insert({3, now.second});
				}
				else if (now.first == 3) {
					if (str[i] == '{') {
						cur->insert({1, now.second + 1});
						cur->insert({4, now.second});
					}
					else if (str[i] == '}') cur->insert({4, now.second});
					else cur->insert({4, now.second});
				}
				else {
					if (str[i] == '{') continue;
					else if (str[i] == '}') cur->insert({2, now.second - 1});
					else cur->insert({3, now.second});
				}
			}
			s[(i + 1) % 2].clear();
		}

		bool pos = 0;
		for (ii now: s[(str.size() + 1) % 2]) {
			if (now.first == 2 && now.second == 0) pos = 1;
		}
		if (pos) cout << "Word #" << test << ": Set\n";
		else cout << "Word #" << test << ": No Set\n";
	}
}