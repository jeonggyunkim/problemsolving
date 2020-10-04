#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x;
	cin >> x;

	string s;
	cin >> s;

	unordered_set<string> set;
	set.insert(s);
	while (1) {
		string t;
		for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
			t += s[i];
			if (i != j) t += s[j];
		}
		if (set.count(t)) {
			s = t;
			break;
		}
		set.insert(t);
		s = t;
	}
	x %= set.size();
	x = set.size() - x;

	while (x--) {
		string t;
		for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
			t += s[i];
			if (i != j) t += s[j];
		}
		s = t;
	}
	cout << s;
}