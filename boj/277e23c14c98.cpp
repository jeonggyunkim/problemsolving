#include <iostream>
#include <vector>
#include <string>
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, N, H;
	cin >> s >> N;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] < '0' || s[i] > '9') H.push_back(s[i]);
	}

	getpi(N);

	int n = H.size(), m = N.size();

	int begin = 0, match = 0;
	while (begin <= n - m) {
		if (match < m && H[begin + match] == N[match]) {
			++match;
			if (match == m) {
				cout << 1;
				return 0;
			}
		}
		else {
			if (match == 0) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
	cout << 0;
}