#include <iostream>
#include <memory.h>
#include <set>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;

iii mark[50][50];
int arr[50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	set<iii> ladder;

	for (int i = 1, j; i < n; ++i) {
		int cnt = 1;
		while (cin >> j, j) {
			ladder.insert({j, i, cnt++});
		}
	}

	while (1) {
		memset(mark, 0, sizeof(mark));
		bool cng = 0;
		for (int i = 0; i < n; ++i) arr[i] = i;
		for (iii u: ladder) {
			int a = arr[get<1>(u) - 1];
			int b = arr[get<1>(u)];
			if (a > b) swap(a, b);
			if (get<0>(mark[a][b])) {
				ladder.erase(mark[a][b]);
				ladder.erase(u);
				cng = 1;
				break;
			}
			mark[a][b] = u;
			swap(arr[get<1>(u) - 1], arr[get<1>(u)]);
		}
		if (!cng) break;
	}

	cout << ladder.size() << '\n';
	for (iii u: ladder) {
		cout << get<1>(u) << ' ' << get<2>(u) << '\n';
	}
}
