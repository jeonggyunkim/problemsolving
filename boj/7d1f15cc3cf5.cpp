#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s[10];
	int num[10] = {};
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
		cin >> s[i];
		for (int j = 1; j < s[i].size(); ++j) {
			if (s[i][j - 1] != s[i][j]) num[i]++;
		}
	}

	int ans = 100;
	do {
		int cnt = 0;
		for (int i = 1; i < n; ++i) {
			if (s[arr[i - 1]].back() != s[arr[i]][0]) cnt++;
		}
		ans = min(ans, cnt);
	} while (next_permutation(arr.begin(), arr.end()));

	for (int i = 0; i < n; ++i) ans += num[i];
	cout << ans;
}