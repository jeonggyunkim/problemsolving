#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	string s, t;
	cin >> s;

	int f1 = 1, f2 = 2;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (f1) {
			if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
				f1--;
				t += s[i];
			}
		}
		else {
			if (f2) {
				if (s[i] == 'A') {
					f2--;
					t += s[i];
				}
			}
			else {
				if (i + 1 >= m - 3) {
					for (int j = 0; j < m - 3; ++j) {
						t += s[i - j];
					}
					reverse(t.begin(), t.end());
					cout << "YES\n" << t;
				}
				else cout << "NO";
				return 0;
			}
		}
	}
	cout << "NO";
}