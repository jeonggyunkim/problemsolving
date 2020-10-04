#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

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

	int len;
	cin >> len;

	string H, N;
	char t;
	for (int i = 0; i < len; ++i) {
		cin >> t;
		H.push_back(t);
	}
	for (int i = 0; i < len - 1; ++i) H.push_back(H[i]);

	for (int i = 0; i < len; ++i) {
		cin >> t;
		N.push_back(t);
	}

	getpi(N);

	int n = H.size(), m = N.size();
	int cnt = 0;

	int begin = 0, match = 0;
	while (begin <= n - m) {
		if (match < m && H[begin + match] == N[match]) {
			++match;
			if (match == m) cnt++;
		}
		else {
			if (match == 0) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}

	int g = gcd(cnt, len);
	cout << cnt / g << '/' << len / g;
}