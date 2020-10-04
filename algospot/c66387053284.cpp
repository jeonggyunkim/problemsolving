#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> pi;

void getpi(string& N) {
	int m = N.size();
	pi.resize(m, 0);

	int begin = 1, match = 0;
	while (begin + match < m) {
		if (N[begin + match] == N[match]) {
			++match;
			pi[begin + match - 1] = match;
		}
		else {
			if (match == 0) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
}

int solve(string& a, string& b) {
	int begin = 0, match = 0;
	int n = a.size();
	while (begin < n) {
		if (match < n && a[begin + match] == b[match]) {
			++match;
			if (begin + match == n) return match;
		}
		else {
			if (match == 0) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		string a, b;
		cin >> a;
		b = a;
		reverse(b.begin(), b.end());

		getpi(b);

		cout << 2 * a.size() - solve(a, b) << '\n';
	}
}
