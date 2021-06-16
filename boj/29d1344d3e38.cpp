#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <memory.h>
using namespace std;

typedef tuple<int, int, int> i3;

long long sum[10000], lmax[10000], rmax[10000], tmax[10000];

void upd(int i, int d, int l, int r, int ind) {
	if (r - l == 1) {
		sum[ind] += d;
		lmax[ind] += d;
		rmax[ind] += d;
		tmax[ind] += d;
		return;
	}
	int mid = (l + r) / 2;
	if (i < mid) upd(i, d, l, mid, 2 * ind);
	else upd(i, d, mid, r, 2 * ind + 1);
	sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
	lmax[ind] = max(lmax[2 * ind], sum[2 * ind] + lmax[2 * ind + 1]);
	rmax[ind] = max(rmax[2 * ind + 1], sum[2 * ind + 1] + rmax[2 * ind]);
	tmax[ind] = max({tmax[2 * ind], tmax[2 * ind + 1], rmax[2 * ind] + lmax[2 * ind + 1]});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<i3> gold;
	map<int, int> reindex;
	int x, y, w;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> w;
		gold.push_back({y, x, w});
		reindex[x] = 0;
	}
	int cnt = 0;
	for (auto it = reindex.begin(); it != reindex.end(); ++it) {
		it->second = cnt++;
	}
	for (int i = 0; i < n; ++i) get<1>(gold[i]) = reindex[get<1>(gold[i])];
	sort(gold.begin(), gold.end());

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i != 0 && get<0>(gold[i]) == get<0>(gold[i - 1])) continue;

		memset(sum, 0, sizeof(sum));
		memset(lmax, 0, sizeof(lmax));
		memset(rmax, 0, sizeof(rmax));
		memset(tmax, 0, sizeof(tmax));

		for (int j = i; j < n; ++j) {
			upd(get<1>(gold[j]), get<2>(gold[j]), 0, n, 1);
			if (j == n - 1 || get<0>(gold[j]) != get<0>(gold[j + 1])) {
				ans = max(ans, tmax[1]);
			}
		}
	}
	cout << ans;
}