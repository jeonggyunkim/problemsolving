#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, d, p, t;
		cin >> n >> d >> p;

		vector<int> graph[50];
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			cin >> t;
			if (t) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}

		double prob[50] = {};
		prob[p] = 1;

		for (int i = 0; i < d; ++i) {
			double temp[50] = {};
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < graph[j].size(); ++k) {
					temp[graph[j][k]] += prob[j] / graph[j].size();
				}
			}
			for (int j = 0; j < n; ++j) prob[j] = temp[j];
		}

		cin >> t;
		int q;
		for (int i = 0; i < t; ++i) {
			cin >> q;
			cout << prob[q] << ' ';
		}
		cout << '\n';
	}
}
