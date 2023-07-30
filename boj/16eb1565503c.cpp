#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t, cnt[3] = {};
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		cnt[t + 1]++;
	}
	if (cnt[1] >= (n + 1) / 2) cout << "INVALID";
	else if (cnt[2] > cnt[0]) cout << "APPROVED";
	else cout << "REJECTED";
}