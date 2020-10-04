#include <bits/stdc++.h>
using namespace std;

map<int, int> m1;
map<int, int> m2;

void factorize(map<int, int>& m, int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			if (m.count(i)) m[i] += cnt;
			else m[i] = cnt;
		}
	}
	if (n != 1) {
		if (m.count(n)) m[n] += 1;
		else m[n] = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;

	factorize(m1, a1);
	factorize(m1, b1);
	factorize(m2, a2);
	factorize(m2, b2);

	int cnt[2][4] = {};

	auto it = m1.begin(), jt = m2.begin();
	while (it != m1.end()) {
		if (it->first == 2 || it->first == 3) {
			cnt[0][it->first] = it->second;
		}
		else break;
		it++;
	}

	while (jt != m2.end()) {
		if (jt->first == 2 || jt->first == 3) {
			cnt[1][jt->first] = jt->second;
		}
		else break;
		jt++;
	}

	while (it != m1.end() || jt != m2.end()) {
		if (it != m1.end() && jt != m2.end()) {
			if (it->first == jt->first && it->second == jt->second) {
				it++; jt++;
			}
			else {
				cout << -1;
				return 0;
			}
		}
		else {
			cout << -1;
			return 0;
		}
	}

	int ans = 0;
	if (cnt[0][3] != cnt[1][3]) {
		if (cnt[0][3] > cnt[1][3]) {
			int d = cnt[0][3] - cnt[1][3];
			cnt[0][3] -= d;
			cnt[0][2] += d;
			ans += d;
			while (d--) {
				if (a1 % 3 == 0) {
					a1 /= 3;
					a1 *= 2;
				}
				else {
					b1 /= 3;
					b1 *= 2;
				}
			}
		}
		else {
			int d = cnt[1][3] - cnt[0][3];
			cnt[1][3] -= d;
			cnt[1][2] += d;
			ans += d;
			while (d--) {
				if (a2 % 3 == 0) {
					a2 /= 3;
					a2 *= 2;
				}
				else {
					b2 /= 3;
					b2 *= 2;
				}
			}
		}
	}

	if (cnt[0][2] != cnt[1][2]) {
		if (cnt[0][2] > cnt[1][2]) {
			int d = cnt[0][2] - cnt[1][2];
			ans += d;
			while (d--) {
				if (a1 % 2 == 0) a1 /= 2;
				else b1 /= 2;
			}
		}
		else {
			int d = cnt[1][2] - cnt[0][2];
			ans += d;
			while (d--) {
				if (a2 % 2 == 0) a2 /= 2;
				else b2 /= 2;
			}
		}
	}

	cout << ans << '\n';
	cout << a1 << ' ' << b1 << '\n';
	cout << a2 << ' ' << b2 << '\n';
}