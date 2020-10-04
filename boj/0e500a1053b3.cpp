#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char a, b;
	int test = 1;
	while (1) {
		cin >> a >> b;
		if (a == '#') break;

		if (test != 1) cout << '\n';
		cout << "Case " << test << '\n';
		int n;
		cin >> n;
		
		string s;
		getline(cin, s);
		
		while (n--) {
			getline(cin, s);
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == a || s[i] == b || s[i] == a - 'a' + 'A' || s[i] == b - 'a' + 'A') {
					s[i] = '_';
				}
			}
			cout << s << '\n';
		}
		test++;
	}
}