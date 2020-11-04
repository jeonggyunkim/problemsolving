#include <iostream>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; ++test) {
		int n;
		string s;
		cin >> n >> s;

		int v[4];
		for (int i = 0; i < 4; ++i) v[i] = -INF;
		int ans = n + 1;
		int begin, end;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'a') v[0] = i + 1;
			else if (s[i] == 'e') {
				v[1] = max(v[0], v[1]);
				v[0] = -1;
			}
			else if (s[i] == 'i') {
				v[2] = max(v[1], v[2]);
				v[1] = -1;
			}
			else if (s[i] == 'o') {
				v[3] = max(v[2], v[3]);
				v[2] = -1;
			}
			else if (s[i] == 'u') {
				if (v[3] != -1) {
					if (ans > i + 1 - v[3]) {
						ans = i + 1 - v[3];
						begin = v[3];
						end = i + 1;
					}
				}
				v[3] = -1;
			}
		}

		cout << "Case #" << test << '\n';
		if (ans != n + 1) cout << begin << ' ' << end << '\n';
		else cout << "-1 -1\n";
	}
}