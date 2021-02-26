#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int x[25010], y[25010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, n, m;
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	for (int i = 1; i <= m; ++i) cin >> y[i];
	x[n + 1] = a;
	y[m + 1] = b;
	sort(x, x + n + 2);
	sort(y, y + m + 2);

	vector<ii> arr;
	for (int i = 0; i <= n; ++i) {
		arr.push_back({x[i + 1] - x[i], 0});
	}
	for (int i = 0; i <= m; ++i) {
		arr.push_back({y[i + 1] - y[i], 1});
	}
	sort(arr.begin(), arr.end());

	long long cnt_g = n + 1, cnt_s = m + 1;

	long long ans = 0;
	bool change = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (!change && (i == 0 || arr[i].second == arr[i - 1].second)) {
			if (arr[i].second) ans += arr[i].first * (cnt_g - 1);
			else ans += arr[i].first * (cnt_s - 1);
		}
		else {
			if (arr[i].second) {
				ans += arr[i].first * (cnt_g - 1);
				cnt_s--;
			}
			else {
				ans += arr[i].first * (cnt_s - 1);
				cnt_g--;
			}

			if (!change) {
				if (arr[i].second) cnt_g -= i;
				else cnt_s -= i;
				cnt_s++;
				cnt_g++;
			}
			change = 1;
		}
	}
	cout << ans;
}