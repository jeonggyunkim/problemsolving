#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		multiset<int> s;
		int n, t;
		cin >> n;

		char op;
		while (n--) {
			cin >> op >> t;
			if (op == 'I') {
				s.insert(t);
			}
			else {
				if (s.empty()) continue;
				if (t == 1) {
					auto it = s.end(); it--;
					s.erase(it);
				}
				else s.erase(s.begin());
			}
		}

		if (s.empty()) cout << "EMPTY\n";
		else {
			cout << *s.rbegin() << ' ' << *s.begin() << '\n';
		}
	}
}