#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, h, t;
	cin >> n >> h;

	vector<int> top(h + 1, 0);
	vector<int> bottom(h + 1, 0);

	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (i & 1) top[t]++;
		else bottom[t]++;
	}

	for (int i = h - 1; i >= 0; --i) {
		bottom[i] += bottom[i + 1];
		top[i] += top[i + 1];
	}

	int ans = 987654321, cnt;
	for (int i = 1; i <= h; ++i) {
		int now = bottom[i] + top[h - i + 1];
		if (now < ans) {
			ans = now;
			cnt = 1;
		}
		else if (ans == now) cnt++;
	}

	cout << ans << ' ' << cnt;
}