#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, key;
	getline(cin, s);
	cin >> key;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') cout << ' ';
		else {
			char c = s[i] - (key[i % key.size()] - 'a' + 1);
			if (c < 'a') c += 26;
			cout << c;
		}
	}
}