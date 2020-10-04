#include <iostream>
#include <vector>
using namespace std;

int m, l;
vector<int> arr;

bool can_cut(int cut, int size) {
	int now = 0;
	int cnt = 0;
	for (int i = 0; i <= m; ++i) {
		now += arr[i];
		if (now >= size) {
			cnt++;
			now = 0;
		}
	}
	return cnt >= cut + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> m >> l;

	arr.resize(m + 1);
	for (int i = 0; i < m; ++i) cin >> arr[i];
	arr[m] = l;
	for (int i = m; i > 0; --i) arr[i] -= arr[i - 1];

	int t;
	while (n--) {
		cin >> t;
		int low = 1, high = l;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (can_cut(t, mid)) low = mid;
			else high = mid;
		}
		cout << low << '\n';
	}
}