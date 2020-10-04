#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int dir = 0, start = 0, ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'R') {
			if (dir == 0) start = 1;
			dir = (dir + 1) % 4;
		}
		else dir = (dir + 3) % 4;

		if (dir == 0) {
			if (s[i] == 'R' && start) ans++;
			start = 0;
		}

		if (start && dir == 0) ans++;
	}

	cout << ans;
}
