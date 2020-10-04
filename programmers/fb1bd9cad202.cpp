#include <string>
using namespace std;

int intlen(int n) {
	int ret = 0;
	while (n) {
		ret++;
		n /= 10;
	}
	return ret;
}

int solution(string s) {
	int ans = s.size();
	for (int len = 1; len <= s.size() / 2; ++len) {
		int now = len + s.size() % len, con = 0;
		for (int i = 1; i < s.size() / len; ++i) {
			bool b = 1;
			for (int j = i * len; j < (i + 1) * len; ++j) {
				if (s[j] != s[j - len]) {
					b = 0;
					break;
				}
			}
			if (b) con++;
			else {
				if (con) {
					now += intlen(con + 1);
					con = 0;
				}
				now += len;
			}
		}
		if (con) now += intlen(con + 1);
		ans = min(ans, now);
	}

	return ans;
}
