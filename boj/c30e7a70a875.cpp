#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		string s, t;
		cin >> s;
		t = s;
		if (t.back() <= 'Z') t.back() = t.back() - 'A' + 'a';
		if (t.back() == 'a' || t.back() == 'e' || t.back() == 'i' || t.back() == 'o' || t.back() == 'u') {
			cout << "Case #" << test << ": " << s << " is ruled by a queen.\n";
		}
		else if (t.back() == 'y') {
			cout << "Case #" << test << ": " << s << " is ruled by nobody.\n";
		}
		else {
			cout << "Case #" << test << ": " << s << " is ruled by a king.\n";
		}
	}
}