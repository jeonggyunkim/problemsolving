#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, x, y;
		cin >> n;

		vector<ii> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			arr[i] = ii(x, y);
		}

		sort(arr.begin(), arr.end());
		int ans = 1, m = arr[0].second;

		for (int i = 1; i < n; ++i) {
			if (arr[i].second < m) {
				m = arr[i].second;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}