#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	vector<int> color(n);
	for (int i = 0; i < n; ++i) {
		cin >> color[i];
	}

	vector<long long> left(n), right(n);
	
	left[0] = 0;
	for (int i = 1; i < n; ++i) {
		int d = color[i - 1] - color[i];
		if (d < 0) d += c;
		left[i] = left[i - 1] + d;
	}

	right[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		int d = color[i + 1] - color[i];
		if (d < 0) d += c;
		right[i] = right[i + 1] + d;
	}

	long long ans = (1LL << 60), ind;
	for (int i = 0; i < n; ++i) {
		long long now = max(left[i], right[i]);
		if (now < ans) {
			ans = now;
			ind = i + 1;
		}
	}
	cout << ind << '\n';
	cout << ans;
}