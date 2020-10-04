#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	vector<int> connect[100];
	int contam[100] = {};

	int N, M;

	scanf("%d %d", &N, &M);
	int t1, t2;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &t1, &t2);
		connect[--t1].push_back(--t2);
		connect[t2].push_back(t1);
	}


	contam[0] = 1;
	queue<int> q;
	q.push(0);
	int u;
	while (q.empty() == false) {
		u = q.front();
		q.pop();
		for (int i = 0; i < connect[u].size(); ++i) {
			if (contam[connect[u][i]] == 0) {
				contam[connect[u][i]] = 1;
				q.push(connect[u][i]);
			}
		}
	}

	int count = 0;
	for (int i = 1; i < N; ++i) count += contam[i];

	cout << count << endl;

	return 0;
}