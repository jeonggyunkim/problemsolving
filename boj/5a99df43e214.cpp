#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	
	while (tc--) {
		int k;
		cin >> k;

		string ans;
		bool first = 1, second = 1;
		for (int i = 31; i >= 0; --i) {
			if (!first) {
				if (second) {
					ans += "*(1+1)";
					second = 0;
				}
				else ans = '(' + ans + ")*(1+1)";
			}
			if (k & (1 << i)) {
				if (!first) {
					ans = '(' + ans + ")+";
				}
				else first = 0;
				ans += '1';
			}
		}
		cout << ans << '\n';
	}
}