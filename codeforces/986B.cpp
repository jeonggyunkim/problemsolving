#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, arr[1000001];
	bool check[1000001] = {};

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (check[i] == 0) {
			cnt++;
			int j = arr[i];
			while (check[j] == 0) {
				check[j] = 1;
				j = arr[j];
			}
		}
	}
	if (cnt & 1) cout << "Um_nik";
	else cout << "Petr";
}