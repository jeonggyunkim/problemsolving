#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = -1;
	while (n--) {
		int a, b, c, score;
		cin >> a >> b >> c;
		if (a == b && b == c) score = 10000 + a * 1000;
		else if (a == b || b == c || c == a) {
			if (a == b) score = 1000 + a * 100;
			if (b == c) score = 1000 + b * 100;
			if (c == a) score = 1000 + c * 100;
		}
		else {
			if (b > c) swap(b, c);
			if (a > b) swap(a, b);
			if (b > c) swap(b, c);
			score = c * 100;
		}

		ans = max(ans, score);
	}

	cout << ans;
}
