#include <iostream>
#include <vector>
#define N 3000000
using namespace std;

class Fenwick {
	private:
		const int n = N;
		vector<int> tree = vector<int>(N + 1, 0);
	public:
		void insert(int i, int d) {
			while (i <= n) {
				tree[i] += d;
				i += (i & -i);
			}
		}

		long long get(int i) {
			long long ret = 0;
			while (i) {
				ret += tree[i];
				i &= (i - 1);
			}
			return ret;
		}
};

int cnt[300010];
int score[3] = {1, 2, 5};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	Fenwick row, value;
	int t;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> t;
			value.insert(cnt[j] + 1, score[i]);
			cnt[j] += t;
			value.insert(cnt[j] + 1, -score[i]);
		}
	}

	int m;
	cin >> m;
	while (m--) {
		cin >> t;
		if (t > N - row.get(N)) {
			cout << 0 << '\n';
			continue;
		}
		int low = 0, high = N;
		while (high - low != 1) {
			int mid = (low + high) / 2;
			int now = mid - row.get(mid);
			if (now >= t) high = mid;
			else low = mid;
		}
		row.insert(high, 1);
		cout << value.get(high) << '\n';
	}
}