#include <iostream>
#define N 1000010
using namespace std;

int mini[N], maxi[N];

void tree(int n, int size) {
	if (n == 0) {
		for (int i = 0; i < size; ++i) cout << '.';
		return;
	}
	if (size == 1) {
		if (n) cout << '#';
		else cout << '.';
		return;
	}

	if (n <= size / 2) {
		tree(n, size / 2);
		tree(0, size / 2);
	}
	else {
		int i = n / 2, j = (n + 1) / 2;
		while ((maxi[j] - mini[i]) <= 1 && i != 0) {
			i--; j++;
		}
		i++; j--;
		tree(j, size / 2);
		tree(i, size / 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int i = 0, p = 1, cnt = 0;
	while (1) {
		while (i <= p && i < N) maxi[i++] = cnt;
		if (i == N) break;
		p *= 2;
		cnt++;
	}

	for (int i = 2; i < N; ++i) {
		mini[i] = min(mini[i / 2], mini[(i + 1) / 2]) + 1;
	}

	int size = 1;
	while (size < n) size *= 2;
	tree(n, size);
}