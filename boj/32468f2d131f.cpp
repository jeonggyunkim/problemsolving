#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n, m;
	scanf("%d %d", &m, &n);

	int tom[1001][1001];

	queue<ii> q;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		scanf("%d", &tom[i][j]);
		if (tom[i][j] == 1) q.push(ii(i, j));
	}

	int i, j;
	ii t;
	while (!q.empty()) {
		t = q.front(); q.pop();
		i = t.first; j = t.second;
		if (i > 0 && tom[i - 1][j] == 0) {
			tom[i - 1][j] = tom[i][j] + 1;
			q.push(ii(i - 1, j));
		}
		if (i < n - 1 && tom[i + 1][j] == 0) {
			tom[i + 1][j] = tom[i][j] + 1;
			q.push(ii(i + 1, j));
		}
		if (j > 0 && tom[i][j - 1] == 0) {
			tom[i][j - 1] = tom[i][j] + 1;
			q.push(ii(i, j - 1));
		}
		if (j < m - 1 && tom[i][j + 1] == 0) {
			tom[i][j + 1] = tom[i][j] + 1;
			q.push(ii(i, j + 1));
		}
	}

	int max = -1;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (tom[i][j] > max) max = tom[i][j];
		if (tom[i][j] == 0) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", max - 1);
}