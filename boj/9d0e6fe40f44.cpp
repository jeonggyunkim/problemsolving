#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MOD 1000000007
#define N 200001
#define N2 400001
using namespace std;

typedef tuple<int, int, int> iii;

int star[200010];
int n;
long long tree[N2 + 1];

void insert(int i, int d) {
	while (i <= N2) {
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

bool comp(iii& a, iii& b) {
	if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
	return get<1>(a) > get<1>(b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<iii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> get<0>(arr[i]) >> get<1>(arr[i]);
		get<2>(arr[i]) = i;
	}
	sort(arr.begin(), arr.end(), comp);

	for (int i = n - 1; i >= 0; --i) {
		star[get<2>(arr[i])] = n - 1 - i - get(get<1>(arr[i]) + N);
		insert(get<1>(arr[i]) + N, 1);
	}

	memset(tree, 0, sizeof(tree));
	sort(arr.begin(), arr.end());

	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		(ans += get(get<1>(arr[i]) + N - 1)) %= MOD;
		insert(get<1>(arr[i]) + N, star[get<2>(arr[i])]);
	}
	cout << ans;
}