#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<string, int> si;

bool comp(string& a, string& b) {
	if (a.size() > b.size()) return true;
	else if (a.size() < b.size()) return false;
	else return a >= b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		string d;
		int n, m;
		cin >> d >> n >> m;
		string n_string = to_string(n);

		vector<char> to_do;
		for (int i = 0; i < d.size(); ++i) to_do.push_back(d[i]);
		sort(to_do.begin(), to_do.end());

		vector<string> rep(n, "");

		queue<si> q;
		for (char i : to_do) {
			if (i != '0' && rep[(i - '0') % n].size() == 0) {
				q.push(make_pair(string(1, i), (i - '0') % n));
				if (i - '0' >= n) rep[(i - '0') % n] = string(1, i);
			}
		}

		while (!q.empty() && rep[m].size() == 0) {
			si t = q.front(); q.pop();
			for (char i : to_do) {
				string ne = t.first + i;
				int mod = (t.second * 10 + i - '0') % n;
				if (rep[mod].size() == 0) {
					q.push(make_pair(ne, mod));
					if (comp(ne, n_string)) rep[mod] = ne;
				}
			}
		}

		if (rep[m].size() != 0) cout << rep[m] << '\n';
		else cout << "IMPOSSIBLE\n";
	}
}
