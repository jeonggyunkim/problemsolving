#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int arr[100000];
int temp[100000];
int ans[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int mx = -1, mi = 1987654321;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
		mi = min(mi, arr[i]);
	}
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += arr[i] - mi;
	}

	if (sum <= k) {
		for (int i = 0; i < n; ++i) cout << mi << ' ';
		return 0;
	}

	int low = 0, high = mx;
	memcpy(ans, arr, sizeof(int) * n);
	while (high - low != 1) {
		int mid = (low + high) / 2;
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		memcpy(temp, arr, sizeof(int) * n);
		for (int i = 0; i < n; ++i) pq.push({arr[i], i});
		sum = 0;
		while (!pq.empty()) {
			ii now = pq.top(); pq.pop();
			int i = now.second, d = now.first;
			if (temp[i] != d) continue;
			if (i && d + mid < temp[i - 1]) {
				sum += temp[i - 1] - d - mid;
				temp[i - 1] = d + mid;
				pq.push({temp[i - 1], i - 1});
			}
			if (i != n - 1 && d + mid < temp[i + 1]) {
				sum += temp[i + 1] - d - mid;
				temp[i + 1] = d + mid;
				pq.push({temp[i + 1], i + 1});
			}
		}
		if (sum <= k) {
			high = mid;
			memcpy(ans, temp, sizeof(int) * n);
		}
		else low = mid;
	}
	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}