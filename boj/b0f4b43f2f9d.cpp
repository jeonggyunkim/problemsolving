#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long k;
	cin >> k;

	vector<long long> ans;
	for (long long i = 2; i * i <= k; ++i) {
		while (k % i == 0) {
			k /= i;
			ans.push_back(i);
		}
	}
	if (k != 1) ans.push_back(k);
	cout << ans.size() << '\n';
	for (long long u: ans) cout << u << ' ';
}