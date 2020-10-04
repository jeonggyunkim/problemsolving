#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

vector<ii> factorize(unsigned int n) {
	vector<ii> ret;
	if (n <= 1) return ret;
	if (n % 2 == 0) {
		int cnt = 0;
		while (n % 2 == 0) {
			cnt++;
			n /= 2;
		}
		ret.push_back(ii(2, cnt));
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			ret.push_back(ii(i, cnt));
		}
	}
	if (n != 1) ret.push_back(ii(n, 1));
	return ret;
}

int main() {
	int s, f, m;
	cin >> s >> f >> m;

	bool np[100001] = {};
	int pcnt[100001] = {};

	np[0] = np[1] = 1;
	for (int i = 2; i * i <= 100000; ++i) {
		if (!np[i]) {
			for (int j = i * i; j <= 100000; j += i) np[j] = 1;
		}
	}
	for (int i = 0; i <= 100000; ++i) {
		if (!np[i]) {
			int t = s + f;
			while (t) {
				t /= i;
				pcnt[i] += t;
			}
			t = s;
			while (t) {
				t /= i;
				pcnt[i] -= t;
			}
			t = f;
			while (t) {
				t /= i;
				pcnt[i] -= t;
			}
		}
	}

	for (int i = m; i >= 1; --i) {
		bool ans = 1;
		vector<ii> fac = factorize(i);
		for (ii u: fac) {
			if (pcnt[u.first] < u.second) ans = 0;
		}
		if (ans) {
			cout << i;
			return 0;
		}
	}
}