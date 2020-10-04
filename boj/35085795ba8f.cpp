#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<vector<int>> edge;
vector<int> safe;

bool dfs(int i, int p) {
	if (safe[i]) return 1;
	safe[i] = 2;
	for (int u: edge[i]) {
		if (u != p) {
			if (dfs(u, i)) {
				safe[i] = 1;
				return 1;
			}
		}
	}
	safe[i] = 0;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> arr(m);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		c = b;
		if (a > b) swap(a, b);
		arr[i] = {a, b, c};			
	}
	sort(arr.begin(), arr.end());
	
	edge.resize(n);
	safe.resize(n, 0);
	for (int i = 0; i < m; ++i) {
		if (i != m - 1 && get<0>(arr[i]) == get<0>(arr[i + 1]) && get<1>(arr[i]) == get<1>(arr[i + 1])) {
			edge[get<0>(arr[i])].push_back(get<1>(arr[i]));
			edge[get<1>(arr[i])].push_back(get<0>(arr[i]));
		}
		else if (i != 0 && get<0>(arr[i]) == get<0>(arr[i - 1]) && get<1>(arr[i]) == get<1>(arr[i - 1])) {
			continue;
		}
		else {
			safe[get<2>(arr[i])] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (!safe[i]) {
			if (!dfs(i, -1)) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}