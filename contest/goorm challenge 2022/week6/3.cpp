#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	string s, t, o;
	getline(cin, s);

	while (tc--) {
		getline(cin, s);
		cin >> o >> t;

		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (c >= 65 && c <= 90) {
				if (o == "E") cout << (char)('A' + (c - 'A' + t[i % t.size()]) % 26);
				else cout << (char)('A' + (c - 'A' + (260 - t[i % t.size()]) % 26) % 26);
			}
			else if (c >= 97 && c <= 122) {
				if (o == "E") cout << (char)('a' + (c - 'a' + t[i % t.size()]) % 26);
				else cout << (char)('a' + (c - 'a' + (260 - t[i % t.size()]) % 26) % 26);
			}
			else cout << c;
		}
		getline(cin, s);
		cout << '\n';
	}
}