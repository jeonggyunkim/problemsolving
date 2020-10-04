#include <iostream>
using namespace std;

int arr[1000010];
bool gong[1000010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	long long k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int a, b, start = -1;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (a == 1 && b == n) swap(a, b);
		gong[a - 1] = 1;
		start = a % n;
	}
	if (start == -1) {
		cout << "YES";
		return 0;
	}
	
	long long sum = 0;
	int mini = 1e9;
	int i = start;
	while (1) {
		mini = min(mini, arr[i]);
		if (gong[i]) {
			sum += mini;
			mini = 1e9;
		}
		if (i == (start + n - 1) % n) break;
		i = (i + 1) % n;
	}
	if (sum <= k) cout << "YES";
	else cout << "NO";
}