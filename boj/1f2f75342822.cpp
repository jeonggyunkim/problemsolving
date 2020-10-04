#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	char input[21];
	while (tc--) {
		int d;
		cin >> d >> input;
		int j = 0;
		while (input[j] != '\0') {
			for (int k = 0; k < d; ++k) cout << (char)input[j];
			++j;
		}
		cout << '\n';
	}
}