#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int totalnum = n * n - n / 2;

	vector<vector<int>> edge(totalnum);

	int cnt = 0;
	int a, b;
	vector<iii> odd(n), even(n - 1);
	for (int i = 0; i < n; ++i) {
		if (i & 1) for (int j = 0; j < n - 1; ++j) {
			cin >> a >> b;
			even[j] = iii(a, b, cnt++);
			if (j && (get<0>(even[j]) == get<1>(even[j - 1]))) {
				edge[get<2>(even[j])].push_back(get<2>(even[j - 1]));
				edge[get<2>(even[j - 1])].push_back(get<2>(even[j]));
			}
		}
		else for (int j = 0; j < n; ++j) {
			cin >> a >> b;
			odd[j] = iii(a, b, cnt++);
			if (j && (get<0>(odd[j]) == get<1>(odd[j - 1]))) {
				edge[get<2>(odd[j])].push_back(get<2>(odd[j - 1]));
				edge[get<2>(odd[j - 1])].push_back(get<2>(odd[j]));
			}
		}
		if (i) {
			if (i & 1) for (int j = 0; j < n - 1; ++j) {
				if (get<1>(odd[j]) == get<0>(even[j])) {
					edge[get<2>(odd[j])].push_back(get<2>(even[j]));
					edge[get<2>(even[j])].push_back(get<2>(odd[j]));
				}
				if (get<0>(odd[j + 1]) == get<1>(even[j])) {
					edge[get<2>(odd[j + 1])].push_back(get<2>(even[j]));
					edge[get<2>(even[j])].push_back(get<2>(odd[j + 1]));
				}
			}
			else for (int j = 0; j < n; ++j) {
				if (j != 0 && (get<0>(odd[j]) == get<1>(even[j - 1]))) {
					edge[get<2>(odd[j])].push_back(get<2>(even[j - 1]));
					edge[get<2>(even[j - 1])].push_back(get<2>(odd[j]));
				}
				if (j != n - 1 && (get<1>(odd[j]) == get<0>(even[j]))) {
					edge[get<2>(odd[j])].push_back(get<2>(even[j]));
					edge[get<2>(even[j])].push_back(get<2>(odd[j]));
				}
			}
		}
	}

	queue<int> q;
	vector<int> d(totalnum, -1);
	vector<int> p(totalnum, -1);

	q.push(0);
	d[0] = 1;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int u: edge[now]) {
			if (d[u] == -1) {
				q.push(u);
				d[u] = d[now] + 1;
				p[u] = now;
			}
		}
	}

	vector<int> ans;
	int ansind = totalnum - 1;
	while (d[ansind] == -1) ansind--;

	cout << d[ansind] << '\n';
	ans.push_back(ansind);
	while (p[ansind] != -1) {
		ansind = p[ansind];
		ans.push_back(ansind);
	}

	for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] + 1 << ' ';
}