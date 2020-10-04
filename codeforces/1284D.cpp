#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

struct Fen {
	int tree[200001] = {};

	void insert(int i) {
		while (i <= 200000) {
			tree[i]++;
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
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> a(n);
	vector<ii> b(n);
	vector<int> low(n);
	vector<int> high(n);
	vector<int> cnta(n, 0);
	vector<int> cntb(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		cin >> b[i].first >> b[i].second;
	}

	map<int, vector<int>> reindex;
	for (int i = 0; i < n; ++i) {
		reindex[a[i].first].push_back(2 * i);
		reindex[a[i].second].push_back(2 * i + 1);
	}
	int cnt = 1;
	for (auto it = reindex.begin(); it != reindex.end(); ++it) {
		for (int u: it->second) {
			if (u & 1) a[u / 2].second = cnt;
			else a[u / 2].first = cnt;
		}
		cnt++;
	}
	reindex.clear();
	for (int i = 0; i < n; ++i) {
		reindex[b[i].first].push_back(2 * i);
		reindex[b[i].second].push_back(2 * i + 1);
	}
	cnt = 1;
	for (auto it = reindex.begin(); it != reindex.end(); ++it) {
		for (int u: it->second) {
			if (u & 1) b[u / 2].second = cnt;
			else b[u / 2].first = cnt;
		}
		cnt++;
	}

	vector<ii> temp(n);
	for (int i = 0; i < n; ++i) temp[i] = {a[i].first, i};
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n; ++i) low[i] = temp[i].second;

	for (int i = 0; i < n; ++i) temp[i] = {a[i].second, i};
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n; ++i) high[i] = temp[i].second;

	{
	Fen lowb, highb;
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		while (ind < n && a[high[ind]].second < a[low[i]].first) {
			lowb.insert(b[high[ind]].first);
			highb.insert(b[high[ind]].second);
			ind++;
		}
		if (highb.get(b[low[i]].first - 1) != lowb.get(b[low[i]].second)) {
			cout << "NO";
			return 0;
		}
		cnta[low[i]] += ind;
	}
	}

	{
	Fen lowb, highb;
	int ind = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		while (ind >= 0 && a[low[ind]].first > a[high[i]].second) {
			lowb.insert(b[low[ind]].first);
			highb.insert(b[low[ind]].second);
			ind--;
		}
		if (highb.get(b[high[i]].first - 1) != lowb.get(b[high[i]].second)) {
			cout << "NO";
			return 0;
		}
		cnta[high[i]] += n - 1 - ind;
	}
	}

	for (int i = 0; i < n; ++i) temp[i] = {b[i].first, i};
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n; ++i) low[i] = temp[i].second;

	for (int i = 0; i < n; ++i) temp[i] = {b[i].second, i};
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n; ++i) high[i] = temp[i].second;

	int ind = 0;
	for (int i = 0; i < n; ++i) {
		while (ind < n && b[high[ind]].second < b[low[i]].first) {
			ind++;
		}
		cntb[low[i]] += ind;
	}

	ind = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		while (ind >= 0 && b[low[ind]].first > b[high[i]].second) {
			ind--;
		}
		cntb[high[i]] += n - 1 - ind;
	}

	for (int i = 0; i < n; ++i) {
		if (cnta[i] != cntb[i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}