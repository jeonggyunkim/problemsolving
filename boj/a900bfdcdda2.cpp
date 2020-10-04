#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
#define N 1024
using namespace std;

typedef pair<int, int> ii;

int d[N][N];
int real[N][N];
vector<int> adj[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			cin >> d[i][j];
			d[j][i] = d[i][j];
		}
		for (int j = 0; j < n; ++j) {
			real[i][j] = j;
		}
	}

	for (int i = n - 1; i > 0; --i) {
		int mini = INF, ind;
		for (int j = 0; j < i; ++j) {
			if (d[i][j] < mini) {
				mini = d[i][j];
				ind = j;
			}
		}
		adj[real[ind][i]].push_back(real[i][ind]);
		adj[real[i][ind]].push_back(real[ind][i]);
		vector<ii> left, right;
		for (int j = 0; j <= i; ++j) {
			if (d[j][ind] < d[j][i]) {
				left.push_back({j, d[j][ind]});
			}
			else {
				right.push_back({j, d[j][i]});
				real[j][ind] = real[j][i];
			}
		}
		for (ii a: left) {
			for (ii b: right) {
				d[a.first][b.first] = d[b.first][a.first] = a.second + b.second;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << adj[i].size() << ' ';
		sort(adj[i].begin(), adj[i].end());
		for (int u: adj[i]) cout << u + 1 << ' ';
		cout << '\n';
	}
}