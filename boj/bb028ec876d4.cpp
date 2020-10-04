#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int first = 0;
	for (int i = 0; i < n; ++i) {
		if (i & 1) first -= arr[i];
		else first += arr[i];
	}
	first /= 2;

	for (int i = 0; i < n; ++i) {
		cout << first << '\n';
		first = arr[i] - first;
	}
}
