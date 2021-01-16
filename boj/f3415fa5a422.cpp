#include <iostream>
#include <vector>
#include <complex>
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

vector<long long> multiply(vector<int> &v, vector<int> &w) {
	vector<base> a(v.begin(), v.end()), b(w.begin(), w.end());
	int n = 2;
	while (n < a.size() + b.size()) n <<= 1;
	a.resize(n); b.resize(n);
	fft(a, 0); fft(b, 0);
	for (int i = 0; i < n; i++) a[i] *= b[i];
	fft(a, 1);
	vector<long long> ret(n);
	for (int i = 0; i < n; ++i) {
		ret[i] = (long long)(a[i].real() > 0 ? a[i].real() + 0.5 : a[i].real() - 0.5);
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int n = 1000000;
	vector<int> prime(n + 1, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= n; ++i) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= n; j += i) prime[j] = 0;
	}
	vector<int> a;
	for (int i = 3; i <= 999997; i += 2) {
		if (prime[i]) a.push_back(1);
		else a.push_back(0);
	}
	vector<long long> ret = multiply(a, a);

	int tc, t;
	cin >> tc;

	while (tc--) {
		cin >> t;
		if (t == 4) cout << "1\n";
		else cout << (ret[t / 2 - 3] + 1) / 2 << '\n';
	}
}