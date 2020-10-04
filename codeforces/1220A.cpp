#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;

	cin >> n >> s;

	int z = 0, o = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'z') z++;
		if (s[i] == 'n') o++;
	}

	while (o--) cout << '1' << ' ';
	while (z--) cout << '0' << ' ';
}