#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<ii> factorize(int n) {
	vector<ii> ret;
	if (n <= 1) return ret;
	if (n % 2 == 0) {
		int cnt = 0;
		while (n % 2 == 0) {
			cnt++;
			n /= 2;
		}
		ret.push_back(ii(2, cnt));
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			ret.push_back(ii(i, cnt));
		}
	}
	if (n != 1) ret.push_back(ii(n, 1));
	return ret;
}

vector<int> divisor(unsigned int n) {
	vector<ii> fact = factorize(n);
	vector<int> ret = {1};
	for (ii u: fact) {
		int s = ret.size();
		int mul = 1;
		for (int i = 0; i < u.second; ++i) {
			mul *= u.first;
			for (int i = 0; i < s; ++i) ret.push_back(ret[i] * mul);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	vector<ii> ans(n);
	map<int, vector<int>> cnt;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		cnt[t].push_back(i);
	}

	for (auto it = cnt.begin(); it != cnt.end(); ++it) {
		vector<int> divi = divisor(it->first);
		if (divi.size() < it->second.size()) {
			cout << "NO";
			return 0;
		}
		else {
			for (int i = 0; i < it->second.size(); ++i) {
				ans[it->second[i]].first = divi[i];
				ans[it->second[i]].second = it->first / divi[i];
			}
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
}