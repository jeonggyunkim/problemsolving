#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int i = 0, j = n - 1;
	long long sum_i = 0, sum_j = 0;
	long long ans = 0;
	while (i <= j) {
		if (sum_i + arr[i] < sum_j + arr[j]) {
			sum_i += arr[i];
			i++;
		}
		else {
			sum_j += arr[j];
			j--;
		}
		if (sum_i == sum_j) ans = sum_i;
	}

	cout << ans;
}