#include <iostream>
using namespace std;

int arr[20000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		arr[i + 10000000]++;
	}

	cin >> m;

	for (int i = 0; i < m; ++i) {
		cin >> t;
		cout << arr[t + 10000000];
	}
}
