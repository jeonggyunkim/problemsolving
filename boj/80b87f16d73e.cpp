#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

vector<vector<int>> todo = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8}, {3, 7}, {4, 6, 8}, {5, 7}};

int arr[9], now;
queue<ii> q;
int visited[370000];

int nth() {
	int r = 8 * arr[0];
	for (int i = 1; i < 8; ++i) {
		for (int j = i + 1; j < 9; ++j) if (arr[i] > arr[j]) r++;
		r *= (8 - i);
	}
	return r;
}

void to_arr(int k) {
	for (int i = 8; i >= 0; i--) {
		arr[i] = k % (9 - i);
		k /= 9 - i;
		for (int j = i + 1; j < 9; j++) if (arr[j] >= arr[i]) arr[j]++;
	}
}

void process(int a, int b) {
	swap(arr[a], arr[b]);
	int n = nth();
	if (visited[n] == -1) {
		visited[n] = visited[now] + 1;
		q.push(ii(n, b));
	}
	swap(arr[a], arr[b]);
}

int main() {
	memset(visited, -1, sizeof(visited));
	for (int i = 0; i < 9; ++i) scanf("%d", arr + i);
	int t = nth(), loc;
	for (int i = 0; i < 9; ++i) if (arr[i] == 0) loc = i;

	visited[t] = 0;
	q.push(ii(t, loc));

	while (!q.empty()) {
		ii i = q.front(); q.pop();
		now = i.first;
		to_arr(now);
		loc = i.second;
		for (int j = 0; j < todo[loc].size(); ++j) process(loc, todo[loc][j]);
	}
	printf("%d\n", visited[46233]);
}