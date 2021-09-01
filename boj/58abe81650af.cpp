#include <iostream>
#include <vector>
#include <memory.h>
#include <tuple>
#include <set>
using namespace std;

typedef tuple<int, int, int> iii;

int bm[1510];
bool vis[1510];
vector<vector<int>> edge;

bool dfs(int a) {
	if (vis[a]) return 0;
	vis[a] = 1;
	
	for (int b: edge[a]) {
		if (bm[b] == -1 || dfs(bm[b])) {
			bm[b] = a;
			return 1;
		}
	}
	return 0;
}

int p[1500];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[a] = b;
}

iii dot[1500];
bool done[1500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) p[i] = i;

	int a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		dot[i] = {a, b, c};
		for (int j = 0; j < i; ++j) {
			if (abs(get<0>(dot[i]) - get<0>(dot[j])) + abs(get<1>(dot[i]) - get<1>(dot[j])) + abs(get<2>(dot[i]) - get<2>(dot[j])) == 1) {
				merge(i, j);
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		if (done[i]) continue;
		vector<int> arr;
		arr.push_back(i);
		done[i] = 1;

		for (int j = i + 1; j < n; ++j) {
			if (find(i) == find(j)) {
				arr.push_back(j);
				done[j] = 1;
			}
		}

		if (arr.size() == 1) ans += 1;
		else {
			edge.clear();
			int odd = 0, even = 0;
			vector<int> name(arr.size());
			for (int j = 0; j < arr.size(); ++j) {
				if ((get<0>(dot[arr[j]]) + get<1>(dot[arr[j]]) + get<2>(dot[arr[j]])) % 2 == 0) name[j] = even++;
				else name[j] = odd++;
			}
			edge.resize(even);

			for (int j = 0; j < arr.size(); ++j) {
				if ((get<0>(dot[arr[j]]) + get<1>(dot[arr[j]]) + get<2>(dot[arr[j]])) % 2 == 0) {
					for (int k = 0; k < arr.size(); ++k) {
						if (abs(get<0>(dot[arr[j]]) - get<0>(dot[arr[k]])) + abs(get<1>(dot[arr[j]]) - get<1>(dot[arr[k]])) + abs(get<2>(dot[arr[j]]) - get<2>(dot[arr[k]])) == 1) {
							edge[name[j]].push_back(name[k]);
						}
					}
				}
			}

			int size = 0;
			memset(bm, -1, sizeof(bm));
			for (int i = 0; i < edge.size(); ++i) {
				memset(vis, 0, sizeof(vis));
				if (dfs(i)) size++;
			}
			ans += size;
		}
	}
	cout << ans;
}