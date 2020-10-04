#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	map<string, ii> m;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		m[s].first = i;
	}

	for (int i = 0; i < n; ++i) {
		cin >> s;
		m[s].second = i;
	}

	int cnt = 0;
	for (auto it = m.begin(); it != m.end(); ++it) {
		ii a = it->second;
		auto jt = it;
		jt++;
		while (jt != m.end()) {
			ii b = jt->second;
			if ((a.first < b.first) == (a.second < b.second)) cnt++;
			jt++;
		}
	}
	cout << cnt << '/' << (n * (n - 1)) / 2;
}