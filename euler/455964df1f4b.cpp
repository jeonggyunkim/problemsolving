#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

long long divSum(int n) {
	vector<ii> arr;
	if (n % 2 == 0) {
		int cnt = 0;
		while (n % 2 == 0) {
			cnt++;
			n /= 2;
		}
		arr.push_back({2, cnt});
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			arr.push_back({i, cnt});
		}
	}
	if (n != 1) arr.push_back({n, 1});

	long long ret = 1;
	for (ii u: arr) {
		int p = 1;
		int sum = 1;
		for (int i = 0; i < u.second; ++i) {
			p *= u.first;
			sum += p;
		}
		ret *= sum;
	}
	return ret;
}

int main() {
	long long d[28124];
	bool abund[28124] = {};
	for (int i = 2; i <= 28123; ++i) d[i] = divSum(i) - i;
	for (int i = 2; i <= 28123; ++i) {
		if (d[i] > i) abund[i] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= 28123; ++i) {
		bool pos = 0;
		for (int j = i / 2; j >= 1; --j) {
			if (abund[j] && abund[i - j]) {
				pos = 1;
				break;
			}
		}
		if (!pos) ans += i;
	}
	cout << ans << endl;
}