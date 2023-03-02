#include <iostream>
using namespace std;

int v[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, sum = 0, cnt = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			sum += v[i];
		}
		for (int i = 0; i < n; ++i) {
			if (n * v[i] >= sum) cnt++;
		}
		cout << cnt << '/' << n << '\n';
	}
}