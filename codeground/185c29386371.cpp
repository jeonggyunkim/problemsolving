#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

long long ccw(ii& p, ii& q, ii& r) {
	return (q.first - p.first) * (r.second - p.second) - (q.second - p.second) * (r.first - p.first);
}

int n;
ii pivot;
ii dot[100000];
bool used[100000];
vector<ii> ans;

void match(vector<int>& arr, int p, int m) {
	if (p == 0 || m == 0) return;

	vector<int> inp = arr;
	pivot = dot[arr[0]];
	sort(arr.begin() + 1, arr.end(), [](int& x, int& y) {
		return ccw(pivot, dot[x], dot[y]) > 0;
	});

	vector<int> s;
	s.push_back(arr[0]); s.push_back(arr[1]);

	int next = 2;
	while (next < arr.size()) {
		while (s.size() >= 2) {
			int first, second;
			second = s.back();
			s.pop_back();
			first = s.back();

			if (ccw(dot[first], dot[second], dot[arr[next]]) > 0) {
				s.push_back(second);
				break;
			}
		}
		s.push_back(arr[next++]);
	}

	int find = 0;
	for (int i = 0; i < s.size(); ++i) {
		int j = (i + 1) % s.size();
		if (used[s[i]] || used[s[j]]) continue;
		if ((s[i] < n) != (s[j] < n)) {
			ans.push_back({s[i], s[j]});
			used[s[i]] = 1;
			used[s[j]] = 1;
			find++;
		}
	}

	if (find) {
		vector<int> nxt;
		for (int u: inp) {
			if (!used[u]) nxt.push_back(u);
		}
		match(nxt, p - find, m - find);
	}
	else {
		if ((s[0] < n) == (p > m)) {
			used[s[0]] = 1;
			used[s[1]] = 1;
			vector<int> nxt;
			for (int u: inp) {
				if (!used[u]) nxt.push_back(u);
			}
			if (s[0] < n) match(nxt, p - 2, m);
			else match(nxt, p, m - 2);
		}
		else {
			vector<int> down, up;
			int np = 0, nm = 0;
			for (int i = 0; i < arr.size(); ++i) {
				if (i) down.push_back(arr[i]);
				if (arr[i] < n) np++;
				else nm++;
				if (np == nm) {
					down.pop_back();
					ans.push_back({arr[0], arr[i]});
					for (int j = i + 1; j < arr.size(); ++j) up.push_back(arr[j]);
					sort(up.begin(), up.end(), [](int& x, int& y) {
						return dot[x] < dot[y];
					});
					break;
				}
			}
			match(down, np - 1, nm - 1);
			match(up, p - np, m - nm);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		memset(used, 0, sizeof(used));
		ans.clear();

		cin >> n;

		vector<int> arr(2 * n);
		for (int i = 0; i < 2 * n; ++i) {
			cin >> dot[i].first >> dot[i].second;
			arr[i] = i;
		}
		sort(arr.begin(), arr.end(), [](int& x, int& y) {
			return dot[x] < dot[y];
		});
		vector<int> tmp;
		int p = 0, m = 0;
		for (int i = 0; i < 2 * n; ++i) {
			tmp.push_back(arr[i]);
			if (arr[i] < n) p++;
			else m++;
			if (i & 1) {
				if (i == 2 * n - 1 || p == m || p + m == 200) {
					match(tmp, p, m);
					tmp.clear();
					p = m = 0;
				}
			}
		}

		cout << "Case #" << test << '\n';
		cout << ans.size() << '\n';
		for (ii u: ans) {
			if (u.first > u.second) swap(u.first, u.second);
			cout << u.first + 1 << ' ' << u.second + 1 - n << '\n';
		}
	}
}