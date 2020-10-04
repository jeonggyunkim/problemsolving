#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int ans[10] = {};
	cin >> s;

	int pow = 1;

	for (int i = s.size() - 1; i >= 0; --i) {
		string pres = s.substr(0, i);
		string posts = s.substr(i + 1, s.size() - 1 - i);
		int pre = pres.size() ? stoi(pres) : 0;
		int post = posts.size() ? stoi(posts) : 0;

		for (int j = 0; j < 10; ++j) ans[j] += pre * pow;
		if (pre) ans[0] -= pow;

		if (i == s.size() - 1) {
			if (pre) ans[0]++;
			for (int j = 1; j <= s[i] - '0'; ++j) ans[j]++;
		}
		else {
			for (int j = 0; j < s[i] - '0'; ++j) {
				if (j == 0 && i == 0) continue;
				ans[j] += pow;
			}
			ans[s[i] - '0'] += post + 1;
		}

		pow *= 10;
	}

	for (int i = 0; i < 10; ++i) cout << ans[i] << ' ';
}