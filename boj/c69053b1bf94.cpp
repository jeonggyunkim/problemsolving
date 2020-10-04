#include <iostream>
using namespace std;

typedef pair<int, int> ii;

ii operator+(ii a, ii b) {
	return ii(a.first + b.first, a.second + b.second);
}

ii operator*(int n, ii a) {
	return ii(n * a.first, n * a.second);
}

ii dx[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
ii rdx[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
ii dy[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

ii find(int n, int m, ii pos, int dir, int rev) {
	ii* ldx;
	if (rev) ldx = rdx;
	else ldx = dx;

	if (n == 2) {
		if (m == 1) return pos;
		else if (m == 2) return pos + dy[dir];
		else if (m == 3) return pos + ldx[dir] + dy[dir];
		else return pos + ldx[dir];
		return pos;
	}
	n /= 2;
	int nn = n * n;
	int next = 0;
	while (m > nn) {
		m -= nn;
		next++;
	}
	if (next == 0) {
		if (rev) dir = (dir + 3) % 4;
		else dir = (dir + 1) % 4;
		rev = 1 - rev;
	}
	else if (next == 1) {
		pos = pos + n * dy[dir];
	}
	else if (next == 2) {
		pos = pos + n * ldx[dir];
		pos = pos + n * dy[dir];
	}
	else {
		pos = pos + (2 * n - 1) * ldx[dir];
		pos = pos + (n - 1) * dy[dir];
		if (rev) dir = (dir + 1) % 4;
		else dir = (dir + 3) % 4;
		rev = 1 - rev;
	}
	return find(n, m, pos, dir, rev);
}

int main() {
	int n, m;
	cin >> n >> m;

	ii ans = find(n, m, ii(1, 1), 0, 0);
	cout << ans.first << ' ' << ans.second;
}