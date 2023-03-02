#include <iostream>
using namespace std;

bool vis[1 << 20];
int arr[100], valid[100];
int button[20], cnt;

void rec(int i) {
	if (i == cnt - 1) {
		cout << button[i] << '\n';
		return;
	}
	cout << button[i] << '\n';
	rec(i + 1);
	cout << button[i] << '\n';
	rec(i + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vis[0] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (vis[arr[i]]) continue;

		valid[i] = 1;
		button[cnt++] = i + 1;
		for (int j = 0; j < (1 << 20); ++j) {
			if (vis[j]) {
				vis[j ^ arr[i]] = 1;
			}
		}
	}

	cout << (1 << cnt) - 1 << '\n';
	for (int i = 0; i < (1 << cnt) - 1; ++i) {
		int j = i + 1;
		cout << button[__builtin_ctz((i ^ (i >> 1)) ^ (j ^ (j >> 1)))] << '\n';
	}
}