#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t, now = 1, rev = 0;
	string s;
	cin >> n;

	while (n--) {
		cin >> s >> t;
		cout << now << ' ';
		if (s[0] == 'H') {
			if (t != now) rev = 1 - rev;
			cout << "NO\n";
		}
		else {
			if (t == now) cout << "YES\n";
			else cout << "NO\n";
		}
		if (rev) {
			now--;
			if (now < 1) now += 12;
		}
		else {
			now++;
			if (now > 12) now -= 12;
		}
	}
}