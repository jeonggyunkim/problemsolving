#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] - 3 - 'A' < 0) cout << (char)(s[i] - 3 + 26);
		else cout << (char)(s[i] - 3);
	}
}