#include <iostream>
using namespace std;

int arr[100001];

int main() {	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	cin >> q;

	int a, b;
	while (q--) {
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << '\n';
	}
}