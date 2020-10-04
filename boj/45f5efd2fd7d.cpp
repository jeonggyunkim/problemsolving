#include <iostream>
using namespace std;

int main() {
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n == 1) cout << "#";
		else if (n == 2) cout << "##\n##";
		else {
			for (int i = 0; i < n; ++i) cout << '#';
			cout << '\n';
			for (int i = 0; i < n - 2; ++i) {
				cout << '#';
				for (int j = 0; j < n - 2; ++j) cout << 'J';
				cout << "#\n";
			}
			for (int i = 0; i < n; ++i) cout << '#';
		}
		cout << "\n\n";
	}
}