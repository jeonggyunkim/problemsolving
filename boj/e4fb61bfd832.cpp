#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<long long, long long> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<int, vector<long long>> mp;
	vector<ii> arr(n);
	for (ii& u: arr) cin >> u.first;
	for (ii& u: arr) cin >> u.second;
	for (ii& u: arr) {
		mp[u.second].push_back(u.first);
	}

	long long ans = 0, max_before = -1;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		long long nowmax = -1;
		for (long long& u: it->second) {
			long long plus = 0, now;
			if (u < it->first) {
				now = (it->first - u + 29) / 30;
				u += now * 30;
				plus += now;
			}
			if (u < max_before) {
				now = (max_before - u + 29) / 30;
				u += now * 30;
				plus += now;
			}
			ans += plus;
			nowmax = max(nowmax, u);
		}
		max_before = nowmax;
	}
	cout << ans;
}