#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, k, s;
	cin >> n >> k >> s;

	if ((n - 1) * k < s || k > s) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	bool right = 0;
	int now = 1;
	long long rem = s - k;
	for (int i = 0; i < k; ++i) {
		int d = min(rem, n - 2);
		rem -= d;
		if (!right) {
			now += 1 + d;
			right = 1;
		}
		else {
			now -= 1 + d;
			right = 0;
		}
		cout << now << ' ';
	}
}