#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n >> m;

	vector<ii> house;
	vector<ii> chicken;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> t;
		if (t == 1) {
			house.push_back({i, j});
		}
		else if (t == 2) {
			chicken.push_back({i, j});
		}
	}

	vector<int> arr(chicken.size(), 0);
	for (int i = 0; i < m; ++i) arr[i] = 1;

	int ans = INF;
	do {
		int sum = 0;
		for (int i = 0; i < house.size(); ++i) {
			int dist = INF;
			for (int j = 0; j < chicken.size(); ++j) {
				if (arr[j]) {
					dist = min(dist, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
				}
			}
			sum += dist;
		}
		ans = min(ans, sum);
	} while (prev_permutation(arr.begin(), arr.end()));

	cout << ans;
}