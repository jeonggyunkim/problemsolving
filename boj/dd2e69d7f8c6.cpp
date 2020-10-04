#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> arr(n + 1, 0);

	int a, b, c;
	cin >> a;
	for (int i = 0; i < m - 1; ++i) {
		cin >> b;
		arr[min(a, b)]++; arr[max(a, b)]--;
		a = b;
	}

	long long ans = 0;
	long long sum = 0;
	for (int i = 1; i < n; ++i) {
		sum += arr[i];
		cin >> a >> b >> c;
		ans += min(a * sum, b * sum + c);
	}

	cout << ans;
}