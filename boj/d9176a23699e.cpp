#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> start(n), end(n);
	for (int i = 0; i < n; ++i) {
		cin >> start[i] >> end[i];
	}
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());

	int i = 0, j = 0, t = 0, cnt = 0, ans = -1;
	while (i < n) {
		t = start[i];
		while (i < n && start[i] == t) {
			i++;
			cnt++;
		}
		while (j < n && end[j] <= t) {
			j++;
			cnt--;
		}
		ans = max(cnt, ans);
	}
	cout << ans;
}