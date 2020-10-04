#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	vector<int> arr;
	for (int i = 1; i < 10; ++i) {
		arr.push_back(i);
	}

	set<int> s;
	do {
		for (int i = 1; i < 8; ++i) {
			for (int j = i + 1; j < 9; ++j) {
				int a = 0, b = 0, c = 0;
				for (int k = 0; k < i; ++k) {
					a *= 10;
					a += arr[k];
				}
				for (int k = i; k < j; ++k) {
					b *= 10;
					b += arr[k];
				}
				for (int k = j; k < 9; ++k) {
					c *= 10;
					c += arr[k];
				}
				if (a * b == c) s.insert(c);
			}
		}
	} while (next_permutation(arr.begin(), arr.end()));

	int ans = 0;
	for (int u: s) ans += u;
	cout << ans << endl;
}