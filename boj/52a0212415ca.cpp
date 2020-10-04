#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, l;
	cin >> n >> l >> w;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int time = 0;
	queue<ii> q;
	int noww = 0, cnt = 0, i = 0;
	while (1) {
		if (!q.empty() && q.front().first == time) {
			noww -= q.front().second;
			q.pop();
			cnt++;
			if (cnt == n) {
				cout << time + 1;
				return 0;
			}
		}
		if (i < n && noww + arr[i] <= w) {
			q.push({time + l, arr[i]});
			noww += arr[i];
			i++;
		}
		time++;
	}
}