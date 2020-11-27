#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;

typedef complex<double> base;

void fft(vector<base> &a, bool inv) {
	int n = a.size(), j = 0;
	vector<base> roots(n / 2);
	for (int i = 1; i < n; i++) {
		int bit = (n >> 1);
		while (j >= bit) {
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	double ang = inv ? -2 * M_PI / n : 2 * M_PI / n;
	for (int i = 0; i < n / 2; i++) {
		roots[i] = base(cos(ang * i), sin(ang * i));
	}
	for (int i = 2; i <= n; i <<= 1) {
		int step = n / i;
		for (int j = 0; j < n; j += i) {
			for (int k = 0; k < i / 2; k++) {
				base u = a[j + k], v = a[j + k + i / 2] * roots[step * k];
				a[j + k] = u + v;
				a[j + k + i / 2] = u - v;
			}
		}
	}
	if (inv) for(int i = 0; i < n; i++) a[i] /= n;
}

vector<int> multiply(vector<int> &v, vector<int> &w) {
	vector<base> a(v.begin(), v.end()), b(w.begin(), w.end());
	int n = 2;
	while (n < a.size() + b.size()) n <<= 1;
	a.resize(n); b.resize(n);
    fft(a, 0); fft(b, 0);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    fft(a, 1);
	vector<int> ret(n);
	for (int i = 0; i < n; ++i) {
		ret[i] = (int)(a[i].real() > 0 ? a[i].real() + 0.5 : a[i].real() - 0.5);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	vector<int> aint(a.size()), bint(b.size());
	for (int i = 0; i < a.size(); ++i) aint[i] = a[i] - '0';
	for (int i = 0; i < b.size(); ++i) bint[i] = b[i] - '0';

	vector<int> ret = multiply(aint, bint);
	string ans;
	for (int i = a.size() + b.size() - 2; i >= 1; --i) {
		ans.push_back(ret[i] % 10 + '0');
		ret[i - 1] += ret[i] / 10;
	}
	while (ret[0]) {
		ans.push_back(ret[0] % 10 + '0');
		ret[0] /= 10;
	}

	reverse(ans.begin(), ans.end());
	if (ans.size() == 0 || ans[0] == '0') cout << 0;
	else cout << ans;
}