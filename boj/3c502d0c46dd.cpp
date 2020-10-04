#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int mul = 1, ans = 0;
		for (int i = 23; i >= 0; --i) {
			if (s[i] == '1') ans += mul;
			mul <<= 1;
		}
		cout << ans << '\n';
	}
}