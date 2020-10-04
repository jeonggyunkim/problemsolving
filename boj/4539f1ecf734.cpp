#include <iostream>
using namespace std;

int arr[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum % 3) cout << "NO";
	else {
		int two = 0;
		for (int i = 0; i < n; ++i) {
			two += arr[i] / 2;
		}
		if (two >= sum / 3) cout << "YES";
		else cout << "NO";
	}
}