#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int cnt[26] = {};
	for (int i = 0; i < s.size(); ++i) cnt[s[i] - 'A']++;

	bool odd = false;
	string ans;
	int oddind;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] & 1) {
			if (odd) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			else {
				for (int j = 0; j < cnt[i] / 2; ++j) ans.push_back(i + 'A');
				odd = true;
				oddind = i;
			}
		}
		else for (int j = 0; j < cnt[i] / 2; ++j) ans.push_back(i + 'A');
	}
	string ans2 = ans;
	reverse(ans2.begin(), ans2.end());
	if (odd) ans.push_back(oddind + 'A');
	ans += ans2;

	cout << ans;
}