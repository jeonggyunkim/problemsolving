#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

bool cal[365][1001];
int mx[365];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
		arr[i].first--; arr[i].second--;
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; ++i) {
		int start = 1;
		while (cal[arr[i].first][start]) start++;
		for (int j = arr[i].first; j <= arr[i].second; ++j) {
			cal[j][start] = 1;
			mx[j] = max(mx[j], start);
		}
	}

	int ans = 0;
	for (int i = 0; i < 365; ++i) {
		if (mx[i]) {
			int start = i, sz = -1;
			while (i < 365 && mx[i]) {
				sz = max(sz, mx[i]);
				i++;
			}
			ans += sz * (i - start);
			i--;
		}
	}
	cout << ans;
}