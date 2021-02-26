#include <iostream>
#include <algorithm>
using namespace std;

int train[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int op, a, b;
	while (m--) {
		cin >> op >> a;
		a--;
		switch (op) {
			case 1:
			cin >> b;
			b--;
			train[a] |= (1 << b);
			break;
			case 2:
			cin >> b;
			b--;
			train[a] &= ~(1 << b);
			break;
			case 3:
			train[a] <<= 1;
			train[a] &= (1 << 20) - 1;
			break;
			case 4:
			train[a] >>= 1;
		}
	}
	sort(train, train + n);
	cout << unique(train, train + n) - train;
}