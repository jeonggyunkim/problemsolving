#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s, t;
	cin >> s;
	for (int i = 1; i < n; ++i) {
		cin >> t;
		if (s[0] != t[0]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}