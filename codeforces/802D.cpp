#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[250];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	int n = 250;
	while (tc--) {
		ll sum = 0, sqsum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}

		double avg = 1. * sum / n;
		double var = 0;
		for (int i = 0; i < n; ++i) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= n;

		if (abs(var - avg) > abs(var - (avg * avg) / 3.0)) cout << "uniform";
		else cout << "poisson";
		cout << '\n';
	}
}