#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	while (n--) {
		cin >> t;
		vector<int> arr(200, 0);
		while (t--) {
			int s, f;
			cin >> s >> f;
			s = (s - 1) / 2;
			f = (f - 1) / 2;
			if (s > f) swap(s, f);
			for (int i = s; i <= f; ++i) arr[i]++;
		}
		int ans = -1;
		for (int i = 0; i < 200; ++i) ans = max(ans, arr[i]);
		cout << ans * 10 << '\n';
	}
}