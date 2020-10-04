#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	vector<int> time(n, 0);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[j].first == i) {
				time[j] += arr[j].second;
				for (int k = 0; k < n; ++k) {
					if (arr[k].first == i + 1) {
						time[k] = max(time[k], time[j] + (j - k) * (j - k));
					}
				}
			}
		}
	}

	for (int j = 0; j < n; ++j) ans = max(ans, time[j]);
	cout << ans;
}