#include <iostream>
#include <map>
using namespace std;

int arr[2010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int zero = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] == 0) zero++;
	}

	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			m[arr[i] + arr[j]]++;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int itself = zero - (arr[i] == 0 ? 1 : 0);
		if (m[arr[i]] > itself) cnt++;
	}
	cout << cnt;
}