#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

// power
// 거듭제곱
int power(long long base, int index, int mod) {
	long long r = 1;
	while (index != 0) {
		if (index & 1) r = (r * base) % mod;
		base = (base * base) % mod;
		index >>= 1;
	}
	return r;
}

// Miller-Rabin Primality test
// 밀러-라빈 소수판별법
bool isPrime(unsigned int n) {
	if (n < 2) return 0;
	if (n % 2 == 0) {
		if (n == 2) return 1;
		else return 0;
	}
	int s = __builtin_ctz(n - 1);
	for (unsigned long long a: {2, 7, 61}) {
		if (a >= n) continue;
		int d = (n - 1) >> s;
		unsigned long long now = 1;
		while (d != 0) {
			if (d & 1) now = (now * a) % n;
			a = (a * a) % n;
			d >>= 1;
		}
		if (now == 1) goto success;
		for (int i = 0; i < s; ++i) {
			if (now == n - 1) goto success;
			now = (now * now) % n;
		}
		return 0;
		success:;
	}
	return 1;
}

// Sieve of Eratosthenes
// 에라토스테네스의 체
const int n = 10000000;
vector<int> prime(n + 1, 1);
prime[0] = prime[1] = 0;
for (int i = 2; i * i <= n; ++i) {
	if (!prime[i]) continue;
	for (int j = i * i; j <= n; j += i) prime[j] = 0;
}


// factorize
// 소인수분해
vector<ii> factorize(unsigned int n) {
	vector<ii> ret;
	if (n <= 1) return ret;
	if (n % 2 == 0) {
		int cnt = 0;
		while (n % 2 == 0) {
			cnt++;
			n /= 2;
		}
		ret.push_back(ii(2, cnt));
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			ret.push_back(ii(i, cnt));
		}
	}
	if (n != 1) ret.push_back(ii(n, 1));
	return ret;
}

// divisor
// 약수
vector<int> divisor(unsigned int n) {
	vector<ii> fact = factorize(n);
	vector<int> ret = {1};
	for (ii u: fact) {
		int s = ret.size();
		int mul = 1;
		for (int i = 0; i < u.second; ++i) {
			mul *= u.first;
			for (int i = 0; i < s; ++i) ret.push_back(ret[i] * mul);
		}
	}
	return ret;
}


// FFT
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
