#include <iostream>
using namespace std;

bool vis[1000000];

int main() {
	int n;
	cin >> n;

	int now = 0, cnt = 0;
	while (1) {
		now = (10 * now + 1) % n;
		cnt++;
		if (now == 0) {
			cout << cnt;
			return 0;
		}
		else if (vis[now]) {
			cout << -1;
			return 0;
		}
		else vis[now] = 1;
	}
}