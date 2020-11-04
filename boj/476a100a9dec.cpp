#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n, s, e;
	cin >> n >> s >> e;

	vector<vector<ii>> cri;
	for (int i = 0; i < e; ++i) {
		string s;
		cin >> s;
		cri.push_back(vector<ii>());

		string t;
		int a, b;
		for (char u: s) {
			if (u == 'x') {
				a = atoi(t.c_str());
				t.clear();
			}
			else if (u == '+') {
				b = atoi(t.c_str());
				t.clear();
				cri[i].push_back({a, b});
			}
			else t += u;
		}
		b = atoi(t.c_str());
		t.clear();
		cri[i].push_back({a, b});
	}

	vector<int> now(n + 1);
	for (int i = 0; i < n; ++i) now[i] = 1;

	int ans = 0;
	while (1) {
		int cnt[s + 1] = {};
		for (int i = 0; i < n; ++i) cnt[now[i]]++;

		for (int i = 0; i < e; ++i) {
			bool pos = 1;
			for (ii u: cri[i]) {
				if (cnt[u.second] < u.first) {
					pos = 0;
					break;
				}
			}
			if (pos) {
				ans++;
				break;
			}
		}
		now[0] += 1;
		for (int i = 0; i < n; ++i) {
			if (now[i] > s) {
				now[i] -= s;
				now[i + 1]++;
			}
			else break;
		}
		if (now.back()) break;
	}
	cout << ans;
}