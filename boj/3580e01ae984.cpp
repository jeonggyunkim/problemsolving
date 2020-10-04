#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	string s;
	cin >> s;

	int con = 0, ans = 0;
	bool now = 1;
	for (int i = 0; i < l; ++i) {
		if (now && s[i] == 'I') {
			con++;
			now = !now;
		}
		else if (!now && s[i] == 'O') {
			con++;
			now = !now;
		}
		else {
			if (s[i] == 'I') {
				con = 1;
				now = 0;
			}
			else {
				con = 0;
				now = 1;
			}
		}
		if (con % 2 == 1 && con > 2 * n) ans++;
	}
	cout << ans;
}