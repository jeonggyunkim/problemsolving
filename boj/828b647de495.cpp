#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> il;
typedef tuple<int, int, int, int> iiii;

struct node {
	int type;
	int x, y;
	int neighbor[4];
	int dist[4];
	il dp[4] = {{-1, 0}, {-1, 0}, {-1, 0}, {-1, 0}};
};

int nextDir[3][4] = {{3, 2, 1, 0}, {1, 0, 3, 2}, {0, 1, 2, 3}};
vector<node> info;

il go(int ind, int dir) {
	node& now = info[ind];
	if (now.dp[dir].first != -1) return now.dp[dir];
	int nextd = nextDir[info[ind].type][dir];

	if (now.neighbor[nextd] == -1) {
		if (now.type == 2) return now.dp[dir] = {1, 0};
		else return now.dp[dir] = {0, 0};
	}
	il next = go(now.neighbor[nextd], nextd);
	if (now.type == 2) {
		return now.dp[dir] = {next.first + 1, next.second + (ll)now.dist[nextd] * next.first};
	}
	else {
		return now.dp[dir] = {next.first, next.second + (ll)now.dist[nextd] * next.first};
	}
}

bool comp(iiii& a, iiii& b) {
	if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
	return get<0>(a) < get<0>(b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> n >> m;

	int k, q;
	cin >> k >> q;

	vector<iiii> arr(k);
	info.resize(k);

	int x, y;
	char type;

	for (int i = 0; i < k; ++i) {
		cin >> x >> y >> type;
		x--; y--;
		if (type == '\\') arr[i] = {x, y, 0, i};
		else if (type == '/') arr[i] = {x, y, 1, i};
		else arr[i] = {x, y, 2, i};
	}

	vector<int> up(m, -1), down(m, -1), left(n, -1), right(n, -1);
	sort(arr.begin(), arr.end());
	for (int i = 0; i < k; ++i) {
		int ind = get<3>(arr[i]);
		if (i == 0 || get<0>(arr[i]) != get<0>(arr[i - 1])) {
			left[get<0>(arr[i])] = ind;
			info[ind].neighbor[1] = -1;
		}
		else {
			info[ind].neighbor[1] = get<3>(arr[i - 1]);
			info[ind].dist[1] = get<1>(arr[i]) - get<1>(arr[i - 1]);
		}
		if (i == k - 1 || get<0>(arr[i + 1]) != get<0>(arr[i])) {
			right[get<0>(arr[i])] = ind;
			info[ind].neighbor[3] = -1;
		}
		else {
			info[ind].neighbor[3] = get<3>(arr[i + 1]);
			info[ind].dist[3] = get<1>(arr[i + 1]) - get<1>(arr[i]);
		}
		info[ind].x = get<0>(arr[i]);
		info[ind].y = get<1>(arr[i]);
		info[ind].type = get<2>(arr[i]);
	}
	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < k; ++i) {
		int ind = get<3>(arr[i]);
		if (i == 0 || get<1>(arr[i]) != get<1>(arr[i - 1])) {
			up[get<1>(arr[i])] = ind;
			info[ind].neighbor[2] = -1;
		}
		else {
			info[ind].neighbor[2] = get<3>(arr[i - 1]);
			info[ind].dist[2] = get<0>(arr[i]) - get<0>(arr[i - 1]);
		}
		if (i == k - 1 || get<1>(arr[i + 1]) != get<1>(arr[i])) {
			down[get<1>(arr[i])] = ind;
			info[ind].neighbor[0] = -1;
		}
		else {
			info[ind].neighbor[0] = get<3>(arr[i + 1]);
			info[ind].dist[0] = get<0>(arr[i + 1]) - get<0>(arr[i]);
		}
	}

	string op;
	while (q--) {
		cin >> op;
		int num = atoi(&op[1]);
		num--;
		if (op[0] == 'U') {
			if (up[num] == -1) cout << "0 0\n";
			else {
				il ans = go(up[num], 0);
				ans.second += (ll)ans.first * (info[up[num]].x + 1);
				cout << ans.first << ' ' << ans.second << '\n';
			}
		}
		else if (op[0] == 'D') {
			if (down[num] == -1) cout << "0 0\n";
			else {
				il ans = go(down[num], 2);
				ans.second += (ll)ans.first * (n - info[down[num]].x);
				cout << ans.first << ' ' << ans.second << '\n';
			}
		}
		else if (op[0] == 'L') {
			if (left[num] == -1) cout << "0 0\n";
			else {
				il ans = go(left[num], 3);
				ans.second += (ll)ans.first * (info[left[num]].y + 1);
				cout << ans.first << ' ' << ans.second << '\n';
			}
		}
		else {
			if (right[num] == -1) cout << "0 0\n";
			else {
				il ans = go(right[num], 1);
				ans.second += (ll)ans.first * (m - info[right[num]].y);
				cout << ans.first << ' ' << ans.second << '\n';
			}
		}
	}
}