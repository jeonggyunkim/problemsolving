#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int x1, x2, y1, y2;
	cin >> x1 >> x2 >> y1 >> y2;

	int cross = 0;
	if (a == 0) {
		if (min(-y1 * b, -y2 * b) < c && c < max(-y1 * b, -y2 * b)) cout << "Poor";
		else cout << "Lucky";
		return 0;
	}
	if (b == 0) {
		if (min(-x1 * a, -x2 * a) < c && c < max(-x1 * a, -x2 * a)) cout << "Poor";
		else cout << "Lucky";
		return 0;
	}

	int p = -c - a * x1;
	int q = -c - a * x2;
	if (min(p, q) < b * y1 && b * y1 < max(p, q)) cross = 1;
	if (min(p, q) < b * y2 && b * y2 < max(p, q)) cross = 1;
	p = -c - b * y1;
	q = -c - b * y2;
	if (min(p, q) < a * x1 && a * x1 < max(p, q)) cross = 1;
	if (min(p, q) < a * x2 && a * x2 < max(p, q)) cross = 1;

	if (cross) cout << "Poor";
	else cout << "Lucky";
}