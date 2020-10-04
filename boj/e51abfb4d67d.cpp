#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k, p;
	cin >> n >> k >> p;

	queue<int> q;
	for (int i = 1; i <= k; ++i) q.push(i);
	
	vector<int> ans;
	while (!q.empty()) {
		for (int i = 0; i < n; ++i) {
			if (i == n - 1) ans.push_back(q.front());
			q.pop();
			if (!q.empty()) {
				for (int j = 0; j < p; ++j) {
					q.push(q.front());
					q.pop();
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int u: ans) cout << u << '\n';
}