#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int sun[200010];
int dosu[200010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	long long sum = 0;
	vector<int> beer;
	for (int i = 0; i < k; ++i) {
		cin >> sun[i] >> dosu[i];
		beer.push_back(sun[i]);
	}

	sort(beer.begin(), beer.end(), greater<int>());
	for (int i = 0; i < n; ++i) sum += beer[i];
	if (sum < m) {
		cout << -1;
		return 0;
	}
	
	long long low = -1, high = (1LL << 31) - 1;
	while (high - low != 1) {
		long long mid = (low + high) / 2;
		vector<int> beer;
		for (int i = 0; i < k; ++i) {
			if (dosu[i] <= mid) beer.push_back(sun[i]);
		}
		if (beer.size() < n) {
			low = mid;
			continue;
		}
		sort(beer.begin(), beer.end(), greater<int>());
		long long sum = 0;
		for (int i = 0; i < n; ++i) sum += beer[i];
		if (sum < m) low = mid;
		else high = mid;
	}
	cout << high;
}