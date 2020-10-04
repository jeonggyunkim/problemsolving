#include <iostream>
using namespace std;

int n, count;

void place(int d, int s1, int s2, int s3) {
	if (d == n) {
		count++;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (s1 & (1 << i)) continue;
		if (s2 & (1 << (d + i))) continue;
		if (s3 & (1 << (d - i + 14))) continue;
		place(d + 1, s1 | (1 << i), s2 | (1 << (d + i)), s3 | (1 << (d - i + 14)));
	}
}

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		cin >> n;
		count = 0;

		place(0, 0, 0, 0);

		cout << count << '\n';
	}
}
