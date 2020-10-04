#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while (1) {
		cin >> s;
		if (s.size() == 1 && s[0] == '0') return 0;

		bool pal = 1;
		for (int i = 0; i < s.size() / 2; ++i) {
			if (s[i] != s[s.size() - 1 - i]) pal = 0;
		}

		if (pal) cout << "yes\n";
		else cout << "no\n";
	}
}