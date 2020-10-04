#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n >> m;

	map<string, set<string>> group;
	map<string, string> member;

	string grp, mem;
	for (int i = 0; i < n; ++i) {
		cin >> grp;
		group[grp];
		cin >> t;
		while (t--) {
			cin >> mem;
			group[grp].insert(mem);
			member[mem] = grp;
		}
	}

	while (m--) {
		cin >> mem >> t;
		if (t) cout << member[mem] << '\n';
		else {
			for (auto it = group[mem].begin(); it != group[mem].end(); ++it) {
				cout << *it << '\n';
			}
		}
	}
}