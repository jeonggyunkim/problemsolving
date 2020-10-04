#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, t;
	cin >> n;
	vector<int> arr(n), op;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < 4; ++i) {
		cin >> t;
		while (t--) op.push_back(i);
	}

	int mina = 1e9 + 10, maxa = -1e9 - 10;
	do {
		int loc = arr[0];
		for (int i = 1; i < n; ++i) {
			if (op[i - 1] == 0) loc += arr[i];
			else if (op[i - 1] == 1) loc -= arr[i];
			else if (op[i - 1] == 2) loc *= arr[i];
			else if (op[i - 1] == 3) loc /= arr[i];
		}
		mina = min(mina, loc);
		maxa = max(maxa, loc);
	} while (next_permutation(op.begin(), op.end()));
	cout << maxa << '\n' << mina;
}