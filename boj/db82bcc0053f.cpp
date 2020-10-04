#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int n, r;

	cin >> s >> r;
	n = s.size();

	vector<bool> mask(n, 0);
	for (int i = 0; i < r; ++i) mask[i] = 1;

	int ans = 0, cnt = 0;
	do {
		int dir = 0,temp = 0;
		for (int i = 0; i < n; ++i) if (mask[i]) temp |= (1 << i);
		for (int size = n; size > 2; --size) {
			int temp2 = 0;
			for (int i = 0; i < size; ++i) {
				if (temp & (1 << i)) {
					if (i == 0) {
						temp2 ^= (1 << 1);
						dir &= ~(1 << 1);
					}
					else if (i == size - 1 || i == size - 2) {
						temp2 ^= (1 << (i - 1));
						dir |= (1 << (i - 1));
					}
					else {
						if (s[i] == 'W') {
							temp2 ^= (1 << (i - 1));
							dir |= (1 << (i - 1));
						}
						else if (s[i] == 'B') {
							temp2 ^= (1 << (i + 1));
							dir &= ~(1 << (i + 1));
						}
						else {
							if (dir & (1 << i)) {
								temp2 ^= (1 << (i + 1));
								dir &= ~(1 << (i + 1));
							}
							else {
								temp2 ^= (1 << (i - 1));
								dir |= (1 << (i - 1));
							}
						}
					}
				}
			}
			temp = temp2;
		}
		ans += __builtin_popcount(temp);
		cnt++;
	} while (prev_permutation(mask.begin(), mask.end()));

	cout.precision(15);
	cout << (double)ans / cnt;
}