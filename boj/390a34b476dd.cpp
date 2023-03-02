#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t, cnt[26] = {};
	string s;
	cin >> n;

	while (n--) {
		cin >> s >> t;
		cnt[s[0] - 'A'] += t;
	}
	if (cnt['S' - 'A'] == 5 || cnt['B' - 'A'] == 5 || cnt['L' - 'A'] == 5 || cnt['P' - 'A'] == 5) cout << "YES";
	else cout << "NO";
}