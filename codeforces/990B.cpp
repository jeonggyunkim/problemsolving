#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> arr(n + 1);

	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end() - 1);
	arr[n] = 1 << 29;

	vector<ii> arr_real;
	int seq = 1;
	for (int i = 0; i < n;) {
		if (arr[i] == arr[i + 1]) {
			seq++;
		}
		else {
			arr_real.push_back(ii(arr[i], seq));
			seq = 1;
		}
		 i++;
	}

	int cnt = n;
	for (int i = 0; i < arr_real.size(); ++i) {
		if (arr_real[i].first < arr_real[i + 1].first && arr_real[i].first + k >= arr_real[i + 1].first) {
			cnt -= arr_real[i].second;
		}
	}

	cout << cnt;
}