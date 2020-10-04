#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

long long cnt_m(int m) {
	long long ans = 0;
	vector<int> s(2 * n + 1);

	int zp = n, add = 0;
	for (int i = 0; i < n; ++i) {
		s[zp]++;
		if (arr[i] < m) {
			zp++;
			add += s[zp];
		}
		else {
			add -= s[zp];
			zp--;
		}
		ans += i + 1 - add;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;

	int s = -1;
	arr.resize(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	cout << cnt_m(m) - cnt_m(m + 1);
}