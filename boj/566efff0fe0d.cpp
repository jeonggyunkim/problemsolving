#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void make_sub(int* arr, vector<int>& sub, int size) {
	for (int i = 0; i <= size; ++i) {
		int sum = 0;
		for (int j = 0; j < i; ++j) sum += arr[j];
		if (i == 0 || i == size) {
			sub.push_back(sum);
			continue;
		}
		int pre = 0, next = i % size;
		for (int j = 0; j < size; ++j) {
			sub.push_back(sum);
			sum += arr[next];
			sum -= arr[pre];
			next = (next + 1) % size;
			pre = (pre + 1) % size;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s, m, n;
	int a[1000], b[1000];
	vector<int> suba, subb;
	cin >> s >> m >> n;
	for (int i = 0; i < m; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];

	make_sub(a, suba, m);
	make_sub(b, subb, n);

	sort(subb.begin(), subb.end());
	long long ans = 0;
	for (int i = 0; i < suba.size(); ++i) {
		auto t = equal_range(subb.begin(), subb.end(), s - suba[i]);
		ans += t.second - t.first;
	}
	cout << ans;
}