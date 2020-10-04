#include <iostream>
using namespace std;

int l[10001], r[10001], p[10001];
int d_left[10001], d_right[10001];
int counter = 1;

void inorder(int n, int d) {
	if (l[n] != -1) inorder(l[n], d + 1);
	if (d_left[d]) d_right[d] = counter++;
	else d_left[d] = counter++;
	if (r[n] != -1) inorder(r[n], d + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a, b, c;
	while (n--) {
		cin >> a >> b >> c;
		l[a] = b;
		p[b] = a;
		r[a] = c;
		p[c] = a;
	}

	int i = 1;
	while (p[i]) i = p[i];
	inorder(i, 1);
	int d = 1, w = -1, ind;
	while (d_left[d]) {
		if (d_right[d]) {
			int t = d_right[d] - d_left[d] + 1;
			if (t > w) {
				w = t;
				ind = d;
			}
		}
		else if (1 > w) {
			w = 1;
			ind = d;
		}
		d++;
	}
	cout << ind << ' ' << w;
}