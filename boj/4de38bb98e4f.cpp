#include <iostream>
using namespace std;

char t[1010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		cin >> t;

		bool app[26] = {};
		for (int i = 0; t[i]; ++i) {
			app[t[i] - 'A'] = 1;
		}

		int ans = 0;
		for (int i = 0; i < 26; ++i) {
			if (!app[i]) ans += 'A' + i;
		}
		cout << ans << '\n';
	}
}