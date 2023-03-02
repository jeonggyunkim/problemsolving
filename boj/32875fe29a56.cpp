#include <iostream>
#include <algorithm>
#define SQ(a) ((a) * (a))
using namespace std;

typedef long long ll;

ll x[4], y[4];
int arr[4];

inline ll dist(int a, int b) {
	return SQ(x[a] - x[b]) + SQ(y[a] - y[b]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		for (int i = 0; i < 4; ++i) cin >> x[i] >> y[i];

		for (int i = 0; i < 4; ++i) arr[i] = i;

		bool ans = 0;
		do {
			bool b = 1;
			b &= dist(arr[0], arr[1]) == dist(arr[1], arr[2]);
			b &= dist(arr[1], arr[2]) == dist(arr[2], arr[3]);
			b &= dist(arr[2], arr[3]) == dist(arr[3], arr[0]);
			b &= dist(arr[0], arr[2]) == dist(arr[1], arr[3]);
			ans |= b;
		} while (next_permutation(arr, arr + 4));
		if (ans) cout << "1\n";
		else cout << "0\n";
	}
}