#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	int one = 0;
	for (int i = 0; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] == 1) one++;
	}
	cin >> t;

	for (int i = 0; i <= n; ++i) {
		if (i + t <= n && arr[i] && arr[i] != 2 && arr[i + t] != 0) {
			int dec = 0;
			if (arr[i] == 1) dec++;
			if (arr[i + t] == 1) dec++;
			if (one == dec) {
				cout << "YES\n";
				cout << i << ' ' << i + t;
				return 0;
			}
		}
	}
	cout << "NO";
}