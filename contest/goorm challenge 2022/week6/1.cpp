#include <iostream>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		int a = 0;
		for (int i = 0; i < s.size(); i += 2) a += s[i] - '0';
		for (int i = 1; i < s.size(); i += 2) {
			if (s[i] != '0') a *= s[i] - '0';
		}
		cout << a % 10 << '\n';
	}
}