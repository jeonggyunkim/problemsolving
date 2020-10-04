#include <iostream>
#include <set>
using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		for (int j = a; j <= b; ++j) {
			arr[j] = i;
		}
	}

	set<int> s;
	for (int i = 1; i <= n; ++i) {
		if (arr[i]) s.insert(arr[i]);
	}

	long long ans = 1;
	for (int i = 0; i < s.size(); ++i) {
		ans *= 2;
	}
	cout << ans;
}