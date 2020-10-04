#include <vector>
#include <algorithm>
using namespace std;

int ans = 9;
bool covered[15];
vector<int> cov;

void solve(int d, int n, vector<int>& weak, vector<int>& dist) {
	bool allCovered = 1;
	for (int i = 0; i < weak.size(); ++i) {
		if (!covered[i]) {
			allCovered = 0;
			break;
		}
	}
	if (allCovered) {
		ans = min(ans, d);
		return;
	}
	if (d == dist.size()) {
		return;
	}
	for (int i = 0; i < weak.size(); ++i) {
		if (!covered[i]) {
			int cnt = 0;
			for (int j = 0; j < weak.size(); ++j) {
				if (covered[j]) continue;
				int dd = weak[j] - weak[i];
				if (dd < 0) dd += n;
				if (dd <= dist[d]) {
					covered[j] = 1;
					cov.push_back(j);
					cnt++;
				}
			}
			solve(d + 1, n, weak, dist);
			while (cnt--) {
				covered[cov.back()] = 0;
				cov.pop_back();
			}
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	for (int i = 0; i < 15; ++i) covered[i] = 0;
	ans = 9;

	sort(dist.rbegin(), dist.rend());

	solve(0, n, weak, dist);

	if (ans == 9) return -1;
	else return ans;
}
