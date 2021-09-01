#include <iostream>
using namespace std;

int arr[5000];
int cnt[400001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, n;
	cin >> w >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	for (int i = 2; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) cnt[arr[i] + arr[j]]++;
	}

	for (int i = 1; i < n - 2; ++i) {
		for (int j = 0; j < i; ++j) {
			int now = w - arr[i] - arr[j];
			if (now >= 0 && now <= 400000 && cnt[now]) {
				cout << "YES";
				return 0;
			}
		}
		for (int j = i + 2; j < n; ++j) {
			cnt[arr[i + 1] + arr[j]]--;
		}
	}
	cout << "NO";
}