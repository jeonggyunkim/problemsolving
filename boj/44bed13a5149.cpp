#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int cal(int num[5], int n) {
	if (n <= 5) {
		int ret = 0;
		for (int i = 0; i < 5; ++i) {
			if (num[i] == n + 1) ret += n + 1;
		}
		return ret;
	}
	if (n == 6) {
		for (int i = 1; i <= 6; ++i) {
			int cnt = 0;
			for (int j = 0; j < 5; ++j) {
				if (num[j] == i) cnt++;
			}
			if (cnt >= 4) return 4 * i;
		}
		return 0;
	}
	if (n == 7) {
		int cnt[6] = {}, sum = 0;
		for (int i = 0; i < 5; ++i) {
			cnt[num[i] - 1]++;
			sum += num[i];
		}
		sort(cnt, cnt + 6);
		if (cnt[4] == 2 && cnt[5] == 3) return sum;
		else return 0;
	}
	int tmp[5];
	memcpy(tmp, num, sizeof(tmp));
	sort(tmp, tmp + 5);
	if (n == 8) {
		int pos = 1;
		for (int i = 0; i < 5; ++i) {
			if (tmp[i] != i + 1) pos = 0;
		}
		if (pos) return 30;
		else return 0;
	}
	if (n == 9) {
		int pos = 1;
		for (int i = 0; i < 5; ++i) {
			if (tmp[i] != i + 2) pos = 0;
		}
		if (pos) return 30;
		else return 0;
	}
	if (n == 10) {
		int pos = 1;
		for (int i = 1; i < 5; ++i) {
			if (tmp[i] != tmp[i - 1]) pos = 0;
		}
		if (pos) return 50;
		else return 0;
	}
	if (n == 11) {
		int sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += tmp[i];
		}
		return sum;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = -1, num[5];
	string s;
	cin >> s >> num[2] >> num[3] >> num[4];

	for (int i = 0; i < 36; ++i) {
		num[0] = i % 6 + 1;
		num[1] = i / 6 + 1;
		for (int j = 0; j < 12; ++j) {
			if (s[j] == 'Y') {
				ans = max(ans, cal(num, j));
			}
		}
	}
	cout << ans;
}