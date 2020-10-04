#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<long long> pos = {1};
	vector<long long> neg = {1};
	int zero = 0, n, s, t;
	int posmin = 0, negmin = 0;
	cin >> n >> s;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t > 0) {
			pos.resize(posmin + t + 1, 0);
			for (int j = posmin; j >= 0; --j) {
				if (pos[j] != 0) pos[j + t] += pos[j];
			}
			posmin += t;
		}
		else if (t < 0) {
			t = -t;
			neg.resize(negmin + t + 1, 0);
			for (int j = negmin; j >= 0; --j) {
				if (neg[j] != 0) neg[j + t] += neg[j];
			}
			negmin += t;
		}
		else zero++;
	}

	long long cnt = 0;
	if (s >= 0) {
		for (int i = s; i < pos.size() && i < s + neg.size(); ++i) {
			cnt += pos[i] * neg[i - s];
		}
	}
	else {
		s = -s;
		for (int i = s; i < neg.size() && i < s + pos.size(); ++i) {
			cnt += neg[i] * pos[i - s];
		}
	}
	cnt <<= zero;
	if (s == 0) cnt--;
	cout << cnt;
}