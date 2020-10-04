#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int node[100010][4];

void del(int i) {
	if (node[i][0]) node[node[i][0]][3] = node[i][3];
	if (node[i][3]) node[node[i][3]][0] = node[i][0];
	if (node[i][2]) node[node[i][2]][1] = node[i][1];
	if (node[i][1]) node[node[i][1]][2] = node[i][2];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<iii> arr(n);
	vector<ii> raw(n);
	int a, b;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		raw[i] = {a, b};
	}

	for (int i = 0; i < n; ++i) arr[i] = {raw[i].first + raw[i].second, raw[i].first, i + 1};

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; ++i) {
		if (i != 0 && get<0>(arr[i]) == get<0>(arr[i - 1])) node[get<2>(arr[i])][2] = get<2>(arr[i - 1]);
		if (i != n - 1 && get<0>(arr[i]) == get<0>(arr[i + 1])) node[get<2>(arr[i])][1] = get<2>(arr[i + 1]);
	}

	for (int i = 0; i < n; ++i) arr[i] = {raw[i].first - raw[i].second, raw[i].first, i + 1};

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; ++i) {
		if (i != 0 && get<0>(arr[i]) == get<0>(arr[i - 1])) node[get<2>(arr[i])][3] = get<2>(arr[i - 1]);
		if (i != n - 1 && get<0>(arr[i]) == get<0>(arr[i + 1])) node[get<2>(arr[i])][0] = get<2>(arr[i + 1]);
	}

	int now = 1;
	for (int i = 0; i < k; ++i) {
		if (node[now][s[i] - 'A']) {
			now = node[now][s[i] - 'A'];
			del(node[now][3 - s[i] + 'A']);
		}
	}
	cout << raw[now - 1].first << ' ' << raw[now - 1].second;
}