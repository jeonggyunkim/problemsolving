#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	string s;
	while (tc--) {
		cin >> s;
		if (s.size() == 7 && s[0] == s[1] && s[0] == s[4] && s[2] == s[3] && s[2] == s[5] && s[2] == s[6] && s[0] != s[2]) cout << "1\n";
		else cout << "0\n";
	}
}