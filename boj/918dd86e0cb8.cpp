#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;

	char t;
	string s1, s2;

	map<string, string> m;
	set<string> p;
	for (int i = 0; i < n; ++i) {
		bool first = 1;
		while (1) {
			s2 = s1;
			cin >> s1;
			if (!first) {
				m[s2] = s1;
			}
			else {
				p.insert(s1);
				first = 0;
			}
			t = getchar();
			if (t == '\n' || t == EOF) {
				m[s1] = "";
				break;
			}
		}
	}

	while (true) {
		if (cin >> s1) {
			if (m.count(s1) && p.count(s1)) {
				if (m[s1] != "") p.insert(m[s1]);
				p.erase(s1);
			}
			else {
				cout << "Impossible";
				return 0;
			}
		}
		else break;
	}

	if (p.empty()) cout << "Possible";
	else cout << "Impossible";
}