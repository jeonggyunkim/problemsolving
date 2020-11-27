#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int board[10][10];

int dist(ii a, ii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, h;
	cin >> n >> m >> h;

	ii house;
	vector<ii> arr;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) house = {i, j};
			if (board[i][j] == 2) arr.push_back({i, j});
		}
	}

	int ans = 0;
	do {
		int health = m;
		ii now = house;
		for (int i = 0; i < arr.size(); ++i) {
			if (dist(now, arr[i]) <= health) {
				health -= dist(now, arr[i]);
				now = arr[i];
				health += h;
			}
			else break;

			if (dist(now, house) <= health) {
				ans = max(ans, i + 1);
			}
		}
	} while (next_permutation(arr.begin(), arr.end()));
	cout << ans;
}