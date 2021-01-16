#include <iostream>
#include <memory.h>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int, int> i4;

int sz;
long long bi[5010];
long long tri[5010];

void binary_search(int left, int right, int cnt) {
	if (right < left) return;
    int mid = (left + right) / 2;
	if (!bi[mid]) bi[mid] = cnt + 1;
    binary_search(left, mid - 1, cnt + 1);
    binary_search(mid + 1, right, cnt + 1);
}

void ternary_search(int left, int right, int cnt) {
	if (right < left) return;
    int left_third = left + (right - left) / 3;
    int right_third = right - (right - left) / 3;
	if (!tri[left_third]) tri[left_third] = cnt + 1;
	if (!tri[right_third]) tri[right_third] = cnt + 2;
    ternary_search(left, left_third - 1, cnt + 2);
    ternary_search(left_third + 1, right_third - 1, cnt + 2);
    ternary_search(right_third + 1, right, cnt + 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	vector<i4> query;
	vector<long long> ans(q);

	int n, s, e;
	for (int i = 0; i < q; ++i) {
		cin >> n >> s >> e;
		query.push_back({n, s, e, i});
	}
	sort(query.begin(), query.end());

	for (int i = 0; i < q; ++i) {
		if (i == 0 || get<0>(query[i]) != get<0>(query[i - 1])) {
			memset(bi, 0, sizeof(bi));
			memset(tri, 0, sizeof(tri));
			binary_search(0, get<0>(query[i]) - 1, 0);
			ternary_search(0, get<0>(query[i]) - 1, 0);

			for (int j = 1; j < get<0>(query[i]); ++j) {
				bi[j] += bi[j - 1];
				tri[j] += tri[j - 1];
			}
		}

		if (get<1>(query[i]) == 0) ans[get<3>(query[i])] = tri[get<2>(query[i])] - bi[get<2>(query[i])];
		else ans[get<3>(query[i])] = tri[get<2>(query[i])] - tri[get<1>(query[i]) - 1] - bi[get<2>(query[i])] + bi[get<1>(query[i]) - 1];
	}

	for (long long u: ans) cout << u << '\n';
}