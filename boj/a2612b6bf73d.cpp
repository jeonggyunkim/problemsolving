#include <iostream>
using namespace std;

int arr[400010];
int now = 200005;

char str[200010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> str;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!arr[now]) arr[now] = i + 1;
		if (str[i] == '(') now++;
		else {
			arr[now] = 0;
			now--;
			if (arr[now]) ans = max(ans, i + 2 - arr[now]);
		}
	}
	cout << ans;
}