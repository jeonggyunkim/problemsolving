#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define INF (1LL << 62)
using namespace std;

typedef pair<long long, int> ii;

int arr[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int zero = 0, t, cnt = 0;
	long long m = 0;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t == 0) zero++;
		else {
			if (t < 0) {
				arr[cnt] = -t;
				m += t;
			}
			else arr[cnt] = t;
			cnt++;
		}
	}
	sort(arr, arr + cnt);

	multiset<ii> st;
	st.insert({0, -1});
	for (int i = 0; i <= k; ++i) st.insert({INF, -1});

	for (int i = 0; i < cnt; ++i) {
		for (auto it = st.begin(); it != st.end(); ++it) {
			auto jt = st.end();
			jt--;
			if (it->first + arr[i] < jt->first) {
				if (it->second == i) continue;
				st.erase(jt);
				st.insert({it->first + arr[i], i});
			}
			else break;
		}
	}

	vector<long long> ans;
	bool exclude = 1;
	for (auto it = st.begin(); it != st.end(); ++it) {
		for (int i = 0; i < (1 << min(zero, 30)); ++i) {
			if (exclude && m + it->first == 0) {
				exclude = 0;
				continue;
			}
			if (ans.size() == k) break;
			ans.push_back(m + it->first);
		}
		if (ans.size() == k) break;
	}
	for (long long u: ans) cout << u << '\n';
}