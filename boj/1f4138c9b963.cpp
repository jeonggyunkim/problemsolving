#include <iostream>
using namespace std;

int arr[200010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int op, a, b;
	int stand = 0;
	while (q--) {
		cin >> op >> a;
		if (op == 1) {
			cin >> b;
			arr[(stand + a - 1) % n] += b;
		}
		else if (op == 2) {
			stand = (stand - a + n) % n;
		}
		else {
			stand = (stand + a) % n;
		}
	}

	for (int i = 0; i < n; ++i) cout << arr[(stand + i) % n] << ' ';
}