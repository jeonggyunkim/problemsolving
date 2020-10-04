#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int t;
	char s[81];

	for (int i = 0; i < T; ++i) {
		cin >> t >> s;
		int j = 0;
		while (s[j] != 0) {
			if (j != t - 1) cout << s[j];
			++j;
		}
		cout << endl;
	}

	return 0;
}