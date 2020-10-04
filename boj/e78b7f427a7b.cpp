#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

vector<int> p;
vector<bool> num;

bool isnum(string& s) {
	if ((s[0] >= '0' && s[0] <= '9') || s[0] == '-') return 1;
	else return 0;
}

int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	map<string, int> m;
	vector<string> ori;

	vector<ii> notsame;
	int ind = 0, i = 0;
	while (true) {
		string v1, v2;
		bool same = 1;
		while (s[i] != '=' && s[i] != '!') v1.push_back(s[i++]);
		if (s[i] == '!') same = 0;
		i += 2;
		while (i < s.size() && s[i] != '&') v2.push_back(s[i++]);

		int n1, n2;
		if (m.count(v1) == 0) {
			m[v1] = ind;
			n1 = ind;
			p.push_back(ind);
			ori.push_back(v1);

			if (isnum(v1)) num.push_back(true);
			else num.push_back(false);

			ind++;
		}
		else n1 = m[v1];

		if (m.count(v2) == 0) {
			m[v2] = ind;
			n2 = ind;
			p.push_back(ind);
			ori.push_back(v2);

			if (isnum(v2)) num.push_back(true);
			else num.push_back(false);

			ind++;
		}
		else n2 = m[v2];

		if (same) merge(n1, n2);
		else notsame.push_back(ii(n1, n2));

		if (i == s.size()) break;
		else {
			i += 2;
			continue;
		}
	}

	bool pf = 1;
	string ans;

	vector<pair<vector<int>, ii>> group(ind, make_pair(vector<int>(), ii(INF, -1)));
	vector<bool> incnum(ind, 0);
	for (int i = 0; i < ind; ++i) {
		int t = find(i);
		group[t].first.push_back(i);
		if (group[t].second.first > ori[i].size()) {
			group[t].second.first = ori[i].size();
			group[t].second.second = i;
		}
		if (num[i]) {
			if (incnum[t]) {
				cout << "0==1";
				return 0;
			}
			incnum[t] = 1;
		}
	}

	for (int i = 0; i < ind; ++i) {
		if (group[i].first.size() > 1) {
			int sst = group[i].second.second;
			for (int u: group[i].first) {
				if (u != sst) {
					if (!pf) ans += "&&";
					else pf = 0;
					ans += ori[sst];
					ans += "==";
					ans += ori[u];
				}
			}
		}
	}

	set<ii> done;
	for (int i = 0; i < notsame.size(); ++i) {
		int a = find(notsame[i].first), b = find(notsame[i].second);
		if (a == b) {
			cout << "0==1";
			return 0;
		}
		if (a > b) swap(a, b);
		if (incnum[a] && incnum[b]) continue;
		if (done.count(ii(a, b)) == 0) {
			if (!pf) ans += "&&";
			else pf = 0;
			ans += ori[group[a].second.second];
			ans += "!=";
			ans += ori[group[b].second.second];
			done.insert(ii(a, b));
		}
	}
	if (ans.size() == 0) cout << "0==0";
	else cout << ans;
}
