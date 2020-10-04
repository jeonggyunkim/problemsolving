#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		string s;
		cin >> s;

		vector<int> arr(s.size(), 0);
		int cnt = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '0') {
				cnt++;
				if (i == s.size() - 1 || s[i + 1] == '1') {
					arr[i] = cnt;
					cnt = 0;
				}
			}
			else cnt = 0;
		}

		int ans = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '1') {
				ans++;
				if (i != s.size() - 1 && s[i + 1] == '0') ans++;
			}
			else {
				if (i < s.size() - 2 && s[i + 1] == '1' && s[i + 2] == '1') ans++;
			}
			if (arr[i]) {
				int j = i + 1;
				int val = 0;
				while (j < s.size()) {
					val *= 2;
					if (s[j] == '1') val++;
					if (j - i + arr[i] >= val) {
						if (j - i > 2) ans++;
					}
					else break;
					j++;
				}
			}
		}

		cout << ans << '\n';
	}
}
