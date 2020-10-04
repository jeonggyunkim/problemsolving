#include <iostream>
#include <algorithm>
#include <cmath>
#define SQ(x) ((x) * (x))
#define EPS 1e-9
using namespace std;

int x[4], y[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; ++i) cin >> x[i] >> y[i];

	int arr[4] = {0, 1, 2, 3};

	double ans = 98765;
	do {
		double dist = 0;

		for (int i = 1; i < 4; ++i) {
			dist += sqrt(SQ(x[arr[i]] - x[arr[i - 1]]) + SQ(y[arr[i]] - y[arr[i - 1]]));
		}
		ans = min(ans, dist);
	} while (next_permutation(arr + 1, arr + 4));

	cout << (int)(ans + EPS);
}