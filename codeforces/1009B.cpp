#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	vector<int> two;
	int one = 0, zero = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') zero++;
		else if (s[i] == '1') one++;
		else {
			two.push_back(zero);
			zero = 0;
		}
	}
	two.push_back(zero);

	if (!two.empty()) {
		for (int i = 0; i < two[0]; ++i) cout << 0;
	}
	for (int i = 0; i < one; ++i) cout << 1;

	for (int i = 1; i < two.size(); ++i) {
		cout << 2;
		for (int j = 0; j < two[i]; ++j) cout << 0;
	}
}