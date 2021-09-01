#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int dp[1010];

typedef pair<int, int> ii;
typedef pair<ii, ii> i4;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	int n;
	cin >> n;

	vector<i4> arr;
	arr.push_back({{1, 1}, {0, 0}});
	arr.push_back({{r, c}, {0, n + 1}});
	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back({{a, b}, {c, i}});
	}

	sort(arr.begin(), arr.end());
	for (int i = n; i >= 0; --i) {
		int mi = 987654321;
		for (int j = i + 1; j < n + 2; ++j) {
				if (arr[i].first.first <= arr[j].first.first && arr[i].first.second <= arr[j].first.second) {
					int dist = abs(arr[i].first.first - arr[j].first.first) + abs(arr[i].first.second - arr[j].first.second);
					mi = min(mi, dist + dp[arr[j].second.second] - arr[i].second.first);
				}
		}
		dp[arr[i].second.second] = max(0, mi);
	}
	cout << dp[0];
}