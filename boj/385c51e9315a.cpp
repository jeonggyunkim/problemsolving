#include <iostream>
#include <string>
#define N 200010
using namespace std;

bool check[1001 * 1001];
string before, seg;
int arr[20];

void strAppend(string& str, long long a) {
	if (a == 0) {
		str += '0';
		return;
	}
	int ind = 0;
	while (a) {
		arr[ind++] = a % 10;
		a /= 10;
	}
	for (int i = ind - 1; i >= 0; --i) str += arr[i] + '0';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q, m;
	cin >> q >> m;

	int a = 1, b = 1, c;
	int rep;
	while (1) {
		int now = a * m + b;
		if (check[now]) {
			rep = now;
			break;
		}
		check[now] = 1;
		c = b;
		(b += a) %= m;
		a = c;
	}

	a = 1, b = 1;
	while (1) {
		int now = a * m + b;
		if (now == rep) break;
		else {
			strAppend(before, a);
			c = b;
			(b += a) %= m;
			a = c;
		}
	}

	strAppend(seg, a);
	c = b;
	(b += a) %= m;
	a = c;
	while (1) {
		int now = a * m + b;
		if (now == rep) break;
		else {
			strAppend(seg, a);
			c = b;
			(b += a) %= m;
			a = c;
		}
	}

	long long t;
	while (q--) {
		cin >> t;
		t--;
		if (t < before.size()) cout << before[t] << '\n';
		else {
			t -= before.size();
			t %= seg.size();
			cout << seg[t] << '\n';
		}
	}
}