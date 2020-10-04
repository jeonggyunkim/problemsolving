#include <iostream>
#include <cmath>
#include <vector>
#define N 4000001
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool notprime[N] = {1, 1};
	for (int i = 2; i <= 2000; ++i) {
		for (int j = i * i; j < N; j += i) notprime[j] = 1;
	}

	vector<long long> sum = {0};
	for (int i = 0; i < N; ++i) if (notprime[i] == 0) sum.push_back(sum.back() + i);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i < sum.size(); ++i) {
		int low = i, high = sum.size() - 1, mid;
		if (sum[low] - sum[i - 1] >= n) {
			if (sum[low] - sum[i - 1] == n) cnt++;
			break;
		}
		if (sum[high] - sum[i - 1] < n) break;
		while (high - low > 1) {
			mid = (low + high) / 2;
			if (sum[mid] - sum[i - 1] >= n) high = mid;
			else low = mid;
		}
		if  (sum[high] - sum[i - 1] == n) cnt++;
	}
	cout << cnt;
}