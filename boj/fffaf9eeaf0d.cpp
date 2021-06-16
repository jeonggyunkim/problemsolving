#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int sum[4000];
int lmax[4000];
int rmax[4000];
int tmax[4000];

void solve(int l, int r, int ind) {
	if (r - l == 1) {
		sum[ind] = arr[l];
		lmax[ind] = arr[l];
		rmax[ind] = arr[l];
		tmax[ind] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	solve(l, mid, ind * 2);
	solve(mid, r, ind * 2 + 1);
	sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
	lmax[ind] = max(lmax[2 * ind], sum[2 * ind] + lmax[2 * ind + 1]);
	rmax[ind] = max(rmax[2 * ind + 1], sum[2 * ind + 1] + rmax[2 * ind]);
	tmax[ind] = max({tmax[2 * ind], tmax[2 * ind + 1], rmax[2 * ind] + lmax[2 * ind + 1]});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) cin >> arr[i];
		solve(0, n, 1);
		cout << tmax[1] << '\n';
	}
}