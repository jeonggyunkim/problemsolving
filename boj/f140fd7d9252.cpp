#include <iostream>
#include <memory.h>
#define N 100010
using namespace std;

bool vis[N];
int ori[N], des[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> ori[i];
	for (int i = 0; i < n; ++i) cin >> des[i];

	int cntOri = 0, cntDes = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			cntOri++;
			int j = i;
			while (!vis[j]) {
				vis[j] = 1;
				j = ori[j] - 1;
			}
		}
	}

	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			cntDes++;
			int j = i;
			while (!vis[j]) {
				vis[j] = 1;
				j = des[j] - 1;
			}
		}
	}

	if ((cntOri & 1) == (cntDes & 1)) cout << "Possible";
	else cout << "Impossible";
}