#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string s;
		cin >> s;

		if (s[0] == '#') break;

		int p = 0;
		for (int i = 0; i < s.size() - 1; ++i) {
			if (s[i] == '1') p++;
		}
		if (s[s.size() - 1] == 'e') {
			s[s.size() - 1] = '0' + p % 2;
		}
		else {
			s[s.size() - 1] = '1' - p % 2;
		}
		cout << s << '\n';
	}
}