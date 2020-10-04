#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;

vector<int> p;

int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	p.resize(n);
	for (int i = 0; i < n; ++i) p[i] = i;

	vector<ii> arr_x(n), arr_y(n);
	int a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		arr_x[i] = ii(a, i);
		arr_y[i] = ii(b, i);
	}

	sort(arr_x.begin(), arr_x.end());
	sort(arr_y.begin(), arr_y.end());

	priority_queue<iii, vector<iii>, greater<iii>> x;
	priority_queue<iii, vector<iii>, greater<iii>> y;

	for (int i = 1; i < n; ++i) {
		x.push(iii(arr_x[i].first - arr_x[i - 1].first, arr_x[i].second, arr_x[i - 1].second));
		y.push(iii(arr_y[i].first - arr_y[i - 1].first, arr_y[i].second, arr_y[i - 1].second));
	}

	vector<iiii> arr(q);
	vector<bool> ans(q, 0);
	for (int i = 0; i < q; ++i) {
		cin >> a >> b >> c;
		a--; b--;
		arr[i] = iiii(c, a, b, i);
	}
	sort(arr.begin(), arr.end());

	int i = 0;
	while (i < q) {
		int d = get<0>(arr[i]);
		while (!x.empty() && get<0>(x.top()) <= d) {
			merge(get<1>(x.top()), get<2>(x.top()));
			x.pop();
		}
		while (!y.empty() && get<0>(y.top()) <= d) {
			merge(get<1>(y.top()), get<2>(y.top()));
			y.pop();
		}
		int l1 = find(get<1>(arr[i]));
		int l2 = find(get<2>(arr[i]));
		if (l1 == l2) {
			ans[get<3>(arr[i])] = 1;
		}
		++i;
	}

	for (int i = 0; i < q; ++i) {
		if (ans[i]) cout << "YES\n";
		else cout << "NO\n";
	}
}
