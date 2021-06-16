#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

bool exist[4000010];
int p[4010010];
int value[4010010];
ii arr[10000];
int index[10000];

int find(int i) {
	if (i == p[i]) return i;
	return p[i] = find(p[i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, t;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		cin >> t;
		exist[t] = 1;
	}
	for (int i = 0; i < k; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + k);

	int ind = 0, j = 0;
	for (int i = 1; i <= n; ++i) {
		while (j < k && arr[j].first < i) {
			index[arr[j].second] = ind;
			p[ind] = ind + 1;
			ind++;
			j++;
		}
		if (exist[i]) {
			p[ind] = ind;
			value[ind] = i;
			ind++;
		}
	}

	for (int i = 0; i < k; ++i) {
		int a = find(index[i]);
		cout << value[a] << '\n';
		p[a] = find(a + 1);
	}
}