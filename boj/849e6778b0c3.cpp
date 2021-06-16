#include <iostream>
#include <vector>
#include <algorithm>
#define N 100000
using namespace std;

typedef pair<int, int> ii;

ii arr[N];
int dp[N];
int num[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);

	num[0] = arr[0].second;
	dp[0] = 1;

	int size = 1, start = 0;
	for (int i = 1; i < n; ++i) {
		int t = arr[i].second;
		if (t < num[size - 1]) {
			int* ptr = lower_bound(num, num + size, t);
			*ptr = t;
			dp[i] = ptr - num + 1;
		}
		else if (t > num[size - 1]) {
			num[size] = t;
			dp[i] = size + 1;
			size++;
			start = i;
		}
	}
	cout << n - size << '\n';

	vector<int> remain;
	remain.push_back(start);
	size--;
	for (int i = start - 1; i >= 0; --i) {
		if (dp[i] == size && arr[i].second < arr[remain.back()].second) {
			remain.push_back(i);
			size--;
		}
	}

	int j = remain.size() - 1;
	for (int i = 0; i < n; ++i) {
		if (j < 0 || i != remain[j]) {
			cout << arr[i].first << '\n';
		}
		else {
			j--;
		}
	}
}