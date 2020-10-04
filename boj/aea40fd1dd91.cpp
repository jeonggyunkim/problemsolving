#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt[8001] = {}, sum = 0, t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		sum += t;
		cnt[t + 4000]++;
	}

	int now = 0, low = -10000, high, mid = -10000;
	int maxOccur = -1, occ2, occ1;
	for (int i = 0; i <= 8000; ++i) {
		if (cnt[i]) {
			if (low == -10000) low = i;
			high = i;
			now += cnt[i];
			if (cnt[i] > maxOccur) {
				maxOccur = cnt[i];
				occ2 = -1;
				occ1 = i;
			}
			else if (cnt[i] == maxOccur && occ2 == -1)  {
				occ2 = i;
			}
			if (mid == -10000 && now >= (n + 1) / 2) mid = i;
		}
	}
	cout << fixed;
	cout.precision(0);
	cout << (double)sum / n << '\n';
	cout << mid - 4000 << '\n';
	if (occ2 == -1) cout << occ1 - 4000 << '\n';
	else cout << occ2 - 4000 << '\n';
	cout << high - low;
}