#include <iostream>
#include <vector>
#include <algorithm>
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

vector<int> div(int n) {
	vector<int> ret = {1};
	if (n % 2 == 0) {
		int a = ret.size();
		while (n % 2 == 0) {
			int b = ret.size();
			for (int i = b - a; i < b; ++i) ret.push_back(ret[i] * 2);
			n /= 2;
		}
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int a = ret.size();
			while (n % i == 0) {
				int b = ret.size();
				for (int j = b - a; j < b; ++j) ret.push_back(ret[j] * i);
				n /= i;
			}
		}
	}
	if (n != 1) {
		int a = ret.size();
		for (int i = 0; i < a; ++i) ret.push_back(ret[i] * n);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int ans = arr[1] - arr[0];
	for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
		ans = gcd(ans, arr[j] - arr[i]);
	}

	vector<int> d = div(ans);
	sort(d.begin(), d.end());
	for (int i = 1; i < d.size(); ++i) cout << d[i] << '\n';
}