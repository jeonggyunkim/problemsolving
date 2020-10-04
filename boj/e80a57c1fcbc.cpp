#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <memory.h>
using namespace std;

vector<int> near(int n) {
	vector<int> ret;
	int t1 = n - n % 10;
	int t2 = n - (n % 100 - n % 10);
	int t3 = n - (n % 1000 - n % 100);
	int t4 = n % 1000;

	for (int i = 0; i < 10; i += 1) if (n != t1 + i) ret.push_back(t1 + i);
	for (int i = 0; i < 100; i += 10) if (n != t2 + i) ret.push_back(t2 + i);
	for (int i = 0; i < 1000; i += 100) if (n != t3 + i) ret.push_back(t3 + i);
	for (int i = 1000; i < 10000; i += 1000) if (n != t4 + i) ret.push_back(t4 + i);

	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	bool prime[10000] = {1, 1};
	for (int i = 2; i < 10000; ++i) {
		if (prime[i] == 0) {
			int j = i * 2;
			while (j < 10000) {
				prime[j] = 1;
				j += i;
			}
		}
	}

	map<int, int> index;
	int num = 0;
	for (int i = 1000; i < 10000; ++i) {
		if (prime[i] == 0) {
			index[i] = num++;
		}
	}

	vector<int> edge[1500];
	for (int i = 1000; i < 10000; ++i) {
		if (prime[i] == 0) {
			vector<int> v = near(i);
			for (int j = 0; j < v.size(); ++j) {
				if (prime[v[j]] == 0) {
					edge[index[i]].push_back(index[v[j]]);
					edge[index[v[j]]].push_back(index[i]);
				}
			}
		}
	}

	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int visited[1500];
		memset(visited, -1, sizeof(visited));

		queue<int> q;
		visited[index[a]] = 0;
		q.push(index[a]);

		while (!q.empty()) {
			int i = q.front(); q.pop();
			for (int j = 0; j < edge[i].size(); ++j) {
				int t = edge[i][j];
				if (visited[t] == -1) {
					visited[t] = visited[i] + 1;
					q.push(t);
				}
			}
		}

		if (visited[index[b]] == -1) printf("Impossible\n");
		else printf("%d\n", visited[index[b]]);
	}
}