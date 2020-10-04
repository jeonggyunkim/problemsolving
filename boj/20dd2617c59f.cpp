#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int buf[40];

bool is_pel(int x, int b) {
	int cnt = 0;
	while (x) {
		buf[cnt++] = x % b;
		x /= b;
	}

	for (int i = 0; i < cnt / 2; ++i) {
		if (buf[i] != buf[cnt - 1 - i]) return 0;
	}
	return 1;
}

vector<int> find_div(int x) {
	vector<int> ret;
	for (int i = 1 ; i * i <= x; ++i) {
		if (x % i == 0) {
			ret.push_back(i);
			if (i * i != x) ret.push_back(x / i);
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main() {
	int x;
	cin >> x;

	int i = 2;
	while (i * i <= x) {
		if (is_pel(x, i)) cout << i << '\n';
		i++;
	}

	vector<int> r = find_div(x);
	for (int u: r) {
		if (u - 1 >= i && u - 1 < x) cout << u - 1 << '\n';
	}
}