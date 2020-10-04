#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, int> li;

int n, m;
int tree[1000000];

void insert(int i, int d) {
	while (i <= m) {
		tree[i] += d;
		i += (i & -i);
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
		i &= (i - 1);
	}
	return ret;
}

int binary_find(int ind) {
	int low = 0, high = m;
	while (high - low != 1) {
		int mid = (low + high) / 2;
		int number = mid - get(mid);
		if (number >= ind) high = mid;
		else low = mid;
	}
	return high;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	long long t;
	cin >> n >> m >> q;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr[i]--;
	}

	vector<li> query(q);
	for (int i = 0; i < q; ++i) {
		cin >> t;
		query[i] = {t, i};
	}
	sort(query.begin(), query.end());

	vector<int> behindCnt(m, 0);
	set<int> s;
	for (int i = n - 1; i >= 0; --i) {
		behindCnt[arr[i]] = s.size();
		s.insert(arr[i]);
	}

	vector<ii> ans(q);
	vector<vector<ii>> toFind(m);
	long long total = 0;
	for (int i = 0, j = 0; i < m; ++i) {
		int now = m - behindCnt[i];
		while (j < q && query[j].first <= total + now) {
			if (now != m) toFind[i].push_back({query[j].first - total, query[j].second});
			else {
				ans[query[j].second] = {i + 1, query[j].first - total};
			}
			j++;
		}
		total += now;
	}
	for (int i = q - 1; i >= 0; --i) {
		if (query[i].first > total) {
			ans[query[i].second] = {-1, -1};
		}
		else break;
	}

	s.clear();
	for (int i = n - 1; i >= 0; --i) {
		if (!toFind[arr[i]].empty() && behindCnt[arr[i]] == s.size()) {
			for (ii u: toFind[arr[i]]) {
				ans[u.second] = {arr[i] + 1, binary_find(u.first)};
			}
		}
		if (s.find(arr[i]) == s.end()) {
			insert(arr[i] + 1, 1);
			s.insert(arr[i]);
		}
	}

	for (ii u: ans) {
		cout << u.first << ' ' << u.second << '\n';
	}
}