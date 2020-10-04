#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	n--;

	int a, b;
	cin >> a;
	while (n--) {
		cin >> b;
		a = __gcd(a, b);
	}

	vector<int> ans;
	for (int i = 1; i * i <= a; ++i) {
		if (a % i == 0) {
			ans.push_back(i);
			if (i * i != a) ans.push_back(a / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int u: ans) cout << u << '\n';
}