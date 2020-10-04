#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int sum[100001] = {};


	for (int i = 1; i <= n; ++i) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	int a, b;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}
}