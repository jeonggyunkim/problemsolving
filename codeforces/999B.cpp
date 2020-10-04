#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int i = 1;
	while (i <= n) {
		if (n % i == 0) {
			string t = s.substr(0, i);
			reverse(t.begin(), t.end());
			s = t + s.substr(i, s.size() - i);
		}
		i++;
	}

	cout << s;
}