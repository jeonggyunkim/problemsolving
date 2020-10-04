#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while (1) {
		vector<string> v;
		while (cin >> s, s != "#") v.push_back(s);

		if (v.empty()) break;

		bool ans = 1;
		for (int i = 0; i < v.size() - 1; ++i) {
			if (v[i].size() != v[i + 1].size()) {
				ans = 0;
			}
			else {
				int cnt = 0;
				for (int j = 0; j < v[i].size(); ++j) {
					if (v[i][j] != v[i + 1][j]) cnt++;
				}
				if (cnt != 1) {
					ans = 0;
				}
			}
		}
		if (ans) cout << "Correct\n";
		else cout << "Incorrect\n";
	}
}