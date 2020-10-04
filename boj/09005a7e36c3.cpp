#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		cout << s[i];
		if (i % 10 == 9) cout << '\n';
	}
}