#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;

	vector<int> to_del;
	for (char t = 'a'; t <= 'z'; ++t) {
		for (int i = 0; i < n; ++i) {
			if (s[i] == t) to_del.push_back(i);
			if (to_del.size() == k) break;
		}
		if (to_del.size() == k) break;
	}

	sort(to_del.begin(), to_del.end());

	int i = 0, ind = 0;
	while (i < n && ind < k) {
		if (i != to_del[ind]) cout << s[i];
		else ind++;
		i++;
	}
	while (i < n) {
		cout << s[i];
		i++;
	}
}