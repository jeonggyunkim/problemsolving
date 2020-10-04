#include <iostream>
using namespace std;

int cnt[128];
char what[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> what[i];
		cnt[what[i]]++;
	}

	int ans = max(max(cnt['P'], cnt['H']), cnt['S']);
	int now[128] = {};
	for (int i = 0; i < n; ++i) {
		cnt[what[i]]--; now[what[i]]++;
		ans = max(ans, max(max(now['P'], now['H']), now['S']) + max(max(cnt['P'], cnt['H']), cnt['S']));
	}
	cout << ans;
}
