#include <iostream>
using namespace std;

int arr[1000000];
bool vis[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr[i]--;
	}

	int ans = -1;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			ans++;
			int j = i;
			while (!vis[j]) {
				vis[j] = 1;
				j = arr[j];
			}
		}
	}
	cout << ans;
}