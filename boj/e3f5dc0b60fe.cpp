#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int i = 0;
	while (i < s.size()) {
		if (s[i] == 'p') {
			if (i + 1 >= s.size() || s[i + 1] != 'i') {
				cout << "NO";
				return 0;
			}
			i += 2;
		}
		else if (s[i] == 'k') {
			if (i + 1 >= s.size() || s[i + 1] != 'a') {
				cout << "NO";
				return 0;
			}
			i += 2;
		}
		else if (s[i] == 'c') {
			if (i + 2 >= s.size() || s[i + 1] != 'h' || s[i + 2] != 'u') {
				cout << "NO";
				return 0;
			}
			i += 3;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}