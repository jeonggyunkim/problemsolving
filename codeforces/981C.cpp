#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a, b;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int three = 0;
	int three_name;
	for (int i = 1; i <= n; ++i) if (v[i].size() >= 3) {
		three++;
		three_name = i;
	}

	if (three >= 2) {
		cout << "No";
		return 0;
	}
	else if (three == 1) {
		cout << "Yes\n";
		cout << v[three_name].size() << '\n';
		for (int i = 0; i < v[three_name].size(); ++i) {
			int t = v[three_name][i], p = three_name;
			while (v[t].size() == 2) {
				if (v[t][0] == p) {
					p = t;
					t = v[t][1];
				}
				else {
					p = t;
					t = v[t][0];
				}
			}
			cout << three_name << ' ' << t << '\n';
		}
	}
	else {
		vector<int> two;
		for (int i = 1; i <= n; ++i) if (v[i].size() == 1) two.push_back(i);
		cout << "Yes\n";
		cout << "1\n";
		cout << two[0] << ' ' << two[1];
	}
}