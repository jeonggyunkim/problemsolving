#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int toInt(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	return 10 + c - 'A';
}

vector<vector<int>> cnt(36, vector<int>(52, 0));

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> sum(52, 0);
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = 0; j < s.size(); ++j) {
			int v = toInt(s[s.size() - 1 - j]);
			cnt[v][51 - j]++;
			sum[51 - j] += v;
		}
	}

	for (int i = 0; i < 36; ++i) {
		for (int j = 0; j < 52; ++j) cnt[i][j] *= 35 - i;
		for (int j = 51; j >= 1; --j) {
			if (cnt[i][j] >= 36) {
				cnt[i][j - 1] += cnt[i][j] / 36;
				cnt[i][j] %= 36;
			}
		}
	}

	sort(cnt.begin(), cnt.end());

	int k;
	cin >> k;

	for (int i = 35; i > 35 - k; --i) {
		for (int j = 0; j < 52; ++j) sum[j] += cnt[i][j];
	}

	for (int i = 51; i >= 1; --i) {
		if (sum[i] >= 36) {
			sum[i - 1] += sum[i] / 36;
			sum[i] %= 36;
		}
	}

	int start = 0;
	while (sum[start] == 0 && start < 52) start++;
	if (start == 52) {
		cout << 0;
		return 0;
	}
	while (start < 52) {
		if (sum[start] >= 10) cout << (char)(sum[start] - 10 + 'A');
		else cout << (char)(sum[start] + '0');
		start++;
	}
}