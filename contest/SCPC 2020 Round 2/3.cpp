#include <bits/stdc++.h>
#define INF (1LL << 60)
using namespace std;

typedef pair<int, int> ii;

int treesz;
int median;
int input[200001];
long long tree[410001];

void insert(int i, int d) {
	while (i <= treesz) {
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

int binary_find() {
	int low = 0, high = treesz;
	while (high - low != 1) {
		int mid = (low + high) / 2;
		int cnt = get(mid);
		if (cnt >= median) high = mid;
		else low = mid;
	}
	return high;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n, k, q;
		cin >> n >> k >> q;

		treesz = n;
		median = (n - k + 3) / 2;

		memset(tree, 0, sizeof(tree));

		for (int i = 0; i < n; ++i) {
			cin >> input[i];
			insert(i + 1, input[i]);
		}

		vector<ii> list;
		for (int i = 1; i + k - 1 <= n; ++i) {
			list.push_back({get(i + k - 1) - get(i - 1), list.size()});
		}

		vector<ii> num;
		for (int qq = 0; qq < q; ++qq) {
			int i, t;
			cin >> i >> t;
			
			int d = t - input[i - 1];
			input[i - 1] = t;
			insert(i, d);

			int cnt = 0, start = -1;
			for (int j = i - k + 1; j <= i; ++j) {
				if (j < 1 || j + k - 1 > n) continue;
				if (start == -1) start = j;
				list.push_back({get(j + k - 1) - get(j - 1), list.size()});
				cnt++;
			}
			num.push_back({start, cnt});
		}

		sort(list.begin(), list.end());
		vector<int> convlist(list.size());
		vector<int> table;
		table.push_back(0);
		int ind = 0;
		for (int i = 0; i < list.size(); ++i) {
			if (i == 0 || (list[i].first != list[i - 1].first)) {
				table.push_back(list[i].first);
				ind++;
			}
			convlist[list[i].second] = ind;
		}

		memset(tree, 0, sizeof(tree));
		treesz = table.size() - 1;

		vector<int> sum(n - k + 1);

		ind = 0;
		for (int i = 0; i < n - k + 1; ++i) {
			sum[i] = convlist[ind++];
			insert(sum[i], 1);
		}

		cout << "Case #" << test << '\n';
		cout << table[binary_find()] << ' ';

		for (int i = 0; i < q; ++i) {
			int start = num[i].first;
			int cnt = num[i].second;
			for (int j = start; j < start + cnt; ++j) {
				insert(sum[j - 1], -1);
			}

			for (int j = start; j < start + cnt; ++j) {
				sum[j - 1] = convlist[ind++];
				insert(sum[j - 1], 1);
			}
			cout << table[binary_find()] << ' ';
		}
		cout << '\n';
	}
}