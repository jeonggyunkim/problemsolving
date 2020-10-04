#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n + 1);
	vector<int> ball(n + 1);

	for (int i = 1; i <= n; ++i) cin >> arr[i];

	int ans = 0;
	for (int i = n; i >= 1; --i) {
		int cnt = 0;
		for (int j = i * 2; j <= n; j += i) {
			if (ball[j]) cnt++;
		}
		cnt %= 2;
		if (arr[i]) {
			if (cnt) ball[i] = 0;
			else {
				ball[i] = 1;
				ans++;
			}
		}
		else {
			if (cnt) {
				ball[i] = 1;
				ans++;
			}
			else ball[i] = 0;
		}
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i) if (ball[i]) cout << i << ' ';
}