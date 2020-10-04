#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#define INF 987654321
using namespace std;

char buf[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, int> name;
	vector<string> index;

	int n, t;
	cin >> n;

	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		name[s] = i;
		index.push_back(s);
	}

	vector<vector<int>> edge(n);
	for (int i = 0; i < n; ++i) {
		cin >> s >> t;
		cin.getline(buf, 1);
		int num = name[s];
		while (t--) {
			cin.getline(buf, 10000);
			string now;

			for (int j = 7; buf[j]; ++j) {
				if (buf[j] == ',') {
					edge[num].push_back(name[now]);
					now.clear();
					j++;
				}
				else now += buf[j];
			}
			edge[num].push_back(name[now]);
		}
	}

	int ans = 98765;
	vector<int> ansvec;
	for (int i = 0; i < n; ++i) {
		queue<int> q;
		vector<int> p(n, -1);
		vector<int> d(n, -1);

		int nowans = 98765;
		vector<int> nowvec;

		q.push(i);
		d[i] = 0;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int u: edge[now]) {
				if (u == i) {
					nowans = d[now] + 1;
					while (now != i) {
						nowvec.push_back(now);
						now = p[now];
					}
					nowvec.push_back(i);
					while (!q.empty()) q.pop();
					break;
				}
				if (d[u] == -1) {
					q.push(u);
					p[u] = now;
					d[u] = d[now] + 1;
				}
			}
		}

		if (nowans < ans) {
			ans = nowans;
			ansvec = nowvec;
		}
	}

	if (ans == 98765) {
		cout << "SHIP IT";
	}
	else {
		for (int i = ansvec.size() - 1; i >= 0; --i) {
			cout << index[ansvec[i]] << ' ';
		}
	}
}