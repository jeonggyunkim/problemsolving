#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	char s[101];
	cin >> s;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			s[i] = s[n - 1 - i];
			if (s[i] == '?') s[i] = 'a';
		}
	}
	cout << s;
}